#include <bits/stdc++.h>

using namespace std;

const long long step = 1000000123LL;
const int N = 1010;
const int NN = (N >> 5) + 10;

unsigned int one = 1;
unsigned int a[N][NN];
unsigned int nei[N][NN];
unsigned int test[N][NN];
int n, nn;
long long hh[N], real_hash[N];

void check_tree(vector < pair <int, int> > tree) {
//  printf("check:\n");
//  for (int i = 0; i < n - 1; i++) printf("%d %d\n", tree[i].first, tree[i].second);
  assert((int)tree.size() == n - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < nn; j++) {
      nei[i][j] = 0;
    }
    nei[i][i >> 5] |= (one << (i & 31));
  }
  for (int i = 0; i < n - 1; i++) {
    int x = tree[i].first;
    int y = tree[i].second;
    nei[x][y >> 5] |= (one << (y & 31));
    nei[y][x >> 5] |= (one << (x & 31));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < nn; j++) {
      test[i][j] = nei[i][j];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int x = tree[i].first;
    int y = tree[i].second;
    for (int j = 0; j < nn; j++) {
      test[x][j] |= nei[y][j];
      test[y][j] |= nei[x][j];
    }
  }
  for (int i = 0; i < n; i++) {
    hh[i] = 0;
    for (int j = 0; j < nn; j++) {
      hh[i] = hh[i] * step + test[i][j];
    }
  }
  sort(hh, hh + n);
  for (int i = 0; i < n; i++) {
    if (hh[i] != real_hash[i]) {
      return;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    printf("%d %d\n", tree[i].first + 1, tree[i].second + 1);
  }
  exit(0);
}

int kb[1 << 16];
bool good_list[N], alive[N];
int not_sub[N][N];
int super[N];
bool in_twos[N];

int main() {
  kb[0] = 0;
  for (int i = 1; i < (1 << 16); i++) {
    kb[i] = kb[i & (i - 1)] + 1;
  }
  scanf("%d", &n);
  nn = ((n - 1) >> 5) + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < nn; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    while (foo--) {
      int bar;
      scanf("%d", &bar);
      bar--;
      a[i][bar >> 5] |= (one << (bar & 31));
    }
  }
  for (int i = 0; i < n; i++) {
    real_hash[i] = 0;
    for (int j = 0; j < nn; j++) {
      real_hash[i] = real_hash[i] * step + a[i][j];
    }
  }
  sort(real_hash, real_hash + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      not_sub[i][j] = 0;
      for (int k = 0; k < nn; k++) {
        unsigned int z = (a[i][k] & (~a[j][k]));
        not_sub[i][j] += (kb[z >> 16] + kb[z & 65535]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    super[i] = 0;
    for (int j = 0; j < n; j++) {
      if (not_sub[i][j] == 0 && not_sub[j][i] > 0) {
        super[i]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    alive[i] = true;
    good_list[i] = true;
  }
  vector < pair <int, int> > known;
  while (true) {
    vector < pair <int, int> > lens;
    for (int i = 0; i < n; i++) {
      if (!good_list[i]) {
        continue;
      }
      int cnt = 0;
      for (int j = 0; j < nn; j++) {
        unsigned int z = a[i][j];
        cnt += (kb[z >> 16] + kb[z & 65535]);
      }
      lens.push_back(make_pair(cnt, i));
    }
    sort(lens.begin(), lens.end());
    int id = -1;
    for (int i = 0; i < (int)lens.size(); i++) {
      if (super[lens[i].second] > 0) {
        id = lens[i].second;
        break;
      }
    }
    if (id == -1) {
      vector <int> v;
      for (int i = 0; i < n; i++) {
        if (alive[i]) {
          v.push_back(i);
        }
      }
      for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++) {
          if (i != j) {
            known.push_back(make_pair(v[i], v[j]));
          }
        }
        check_tree(known);
        for (int j = 0; j < (int)v.size(); j++) {
          if (i != j) {
            known.pop_back();
          }
        }
      }
      assert(false);
    }
    vector <int> ones;
    vector < pair <int, int> > twos;
    for (int i = 0; i < n; i++) {
      if (!good_list[i]) {
        continue;
      }
      int inter = 0;
      for (int j = 0; j < nn; j++) {
        unsigned int z = a[id][j] & a[i][j];
        inter += (kb[z >> 16] + kb[z & 65535]);
      }
      if (inter == 1) {
        int x = -1;
        for (int j = 0; j < nn; j++) {
          unsigned int z = a[id][j] & a[i][j];
          if (z > 0) {
            for (int k = 0; k < 32; k++) {
              if (z & (one << k)) {
                x = j * 32 + k;
              }
            }
          }
        }
        ones.push_back(x);
      }
      if (inter == 2) {
        int x = -1, y = -1;
        for (int j = 0; j < nn; j++) {
          unsigned int z = a[id][j] & a[i][j];
          if (z > 0) {
            for (int k = 0; k < 32; k++) {
              if (z & (one << k)) {
                if (x == -1) x = j * 32 + k;
                else y = j * 32 + k;
              }
            }
          }
        }
        twos.push_back(make_pair(x, y));
      }
    }
    assert(twos.size() > 0);
    vector <int> cand;
    for (int q = 0; q < 2; q++) {
      int x = (q == 0 ? twos[0].first : twos[0].second);
      bool ok = true;
      for (int i = 0; i < (int)twos.size(); i++) {
        if (twos[i].first != x && twos[i].second != x) {
          ok = false;
        }
      }
      for (int i = 0; i < (int)ones.size(); i++) {
        if (ones[i] == x) {
          ok = false;
        }
      }
      if (ok) {
        cand.push_back(x);
      }
    }
    assert(cand.size() > 0);
    if (cand.size() == 2) {
      vector <int> s1, s2;
      for (int i = 0; i < n; i++) {
        if (!alive[i] || i == cand[0] || i == cand[1]) {
          continue;
        }
        if (a[id][i >> 5] & (one << (i & 31))) {
          s1.push_back(i);
        } else {
          s2.push_back(i);
        }
      }
      known.push_back(make_pair(cand[0], cand[1]));
      for (int rot = 0; rot < 2; rot++) {
        vector < pair <int, int> > tree = known;
        for (int i = 0; i < (int)s1.size(); i++) {
          tree.push_back(make_pair(s1[i], cand[0]));
        }
        for (int i = 0; i < (int)s2.size(); i++) {
          tree.push_back(make_pair(s2[i], cand[1]));
        }
        check_tree(tree);
        swap(s1, s2);
      }
      assert(false);
    }
    int center = cand[0];
    for (int i = 0; i < n; i++) {
      in_twos[i] = false;
    }
    for (int i = 0; i < (int)twos.size(); i++) {
      in_twos[twos[i].first] = true;
      in_twos[twos[i].second] = true;
    }
    vector <int> leaves;
    for (int i = 0; i < n; i++) {
      if (!alive[i] || i == center) {
        continue;
      }
      if (a[id][i >> 5] & (one << (i & 31))) {
        if (!in_twos[i]) {
          leaves.push_back(i);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (good_list[i] && not_sub[id][i] == 0 && not_sub[i][id] == 0) {
        good_list[i] = false;
      }
    }
    assert(leaves.size() > 0);
    for (int q = 0; q < (int)leaves.size(); q++) {
      int x = leaves[q];
      known.push_back(make_pair(center, x));
      alive[x] = false;
      vector <int> has, not_has;
      for (int i = 0; i < n; i++) {
        if (!good_list[i]) {
          continue;
        }
        if (a[i][x >> 5] & (one << (x & 31))) {
          has.push_back(i);
          a[i][x >> 5] ^= (one << (x & 31));
        } else {
          not_has.push_back(i);
        }
      }
      int hs = has.size(), ns = not_has.size();
      for (int i = 0; i < hs; i++) {
        for (int j = 0; j < ns; j++) {
          int x = has[i];
          int y = not_has[j];
          if (not_sub[x][y] == 0 && not_sub[y][x] > 0) {
            super[x]--;
          }
          if (not_sub[y][x] == 0 && not_sub[x][y] > 0) {
            super[y]--;
          }
          not_sub[x][y]--;
          if (not_sub[x][y] == 0 && not_sub[y][x] > 0) {
            super[x]++;
          }
          if (not_sub[y][x] == 0 && not_sub[x][y] > 0) {
            super[y]++;
          }
        }
      }
    }
  }
  return 0;
}
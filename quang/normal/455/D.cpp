#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 320;

int n, m, numblock;
int cnt[N][M];
vector <int> a[M];
int b[N], top;

void rebuild() {
  top = 0;
  for (int i = 0; i < numblock; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      b[top++] = a[i][j];
      cnt[a[i][j]][i]--;
    }
    a[i].clear();
  }
  for (int i = 0; i < n; i++) {
    a[i / m].push_back(b[i]);
    cnt[b[i]][i / m]++;
  }
}

pair<int, int> pos(int x) {
  for (int i = 0; i < numblock; i++) {
    if (x < a[i].size()) {
      return make_pair(i, x);
    } else {
      x -= a[i].size();
    }
  }
}

void build(int l, int r) {
  pair<int, int> ll = pos(l);
  pair<int, int> rr = pos(r);
  int valr;
  valr = a[rr.first][rr.second];
  cnt[valr][ll.first]++;
  cnt[valr][rr.first]--;
  a[rr.first].erase(a[rr.first].begin() + rr.second);
  a[ll.first].insert(a[ll.first].begin() + ll.second, valr);
}

int query(int l, int r, int k) {
  pair<int, int> ll = pos(l);
  pair<int, int> rr = pos(r);
  int res = 0;
  if (ll.first == rr.first) {
    for (int i = ll.second; i <= rr.second; i++) {
      if (a[ll.first][i] == k) {
        res++;
      }
    }
    return res;
  }
  for (int i = ll.second; i < a[ll.first].size(); i++) {
    if (a[ll.first][i] == k) {
      res++;
    }
  }
  for (int i = 0; i <= rr.second; i++) {
    if (a[rr.first][i] == k) {
      res++;
    }
  }
  for (int i = ll.first + 1; i < rr.first; i++) {
    res += cnt[k][i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  m = sqrt(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i / m].push_back(x);
    cnt[x][i / m]++;
  }
  numblock = (n - 1) / m + 1;
  int q;
  cin >> q;
  int lastans = 0;
  while (q--) {
    if (q % m == 0) {
      rebuild();
    }
    int type, l, r, k;
    cin >> type >> l >> r;
    l--, r--;
    l = (l + lastans) % n;
    r = (r + lastans) % n;
    if (l > r) {
      swap(l, r);
    }
    if (type == 1) {
      build(l, r);
    } else {
      cin >> k;
      k = (k + lastans - 1) % n + 1;
      lastans = query(l, r, k);
      cout << lastans << endl;
    }
  }
  return 0;
}
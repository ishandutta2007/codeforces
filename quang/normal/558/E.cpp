#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef pair<int, int> pi;

int n, q, m;
string a;
int sl;
int c[350][30];
vector <pi> b[350];

vector<int> turn(const vector<pi> &a) {
  vector<int> res;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].second; j++) {
      res.push_back(a[i].first);
    }
  }
  return res;
}

void tang(int l, int r) {
  int bl = l / m;
  int br = r / m;
  if (bl == br) {
    vector <int> x = turn(b[bl]);
    b[bl].clear();
    int posl = l - m * bl;
    int posr = r - m * bl;
    sort(x.begin() + posl, x.begin() + posr + 1);
    for (int i = 0; i < x.size(); i++) {
      b[bl].push_back(pi(x[i], 1));
    }
    return;
  }
  int posl = l - m * bl;
  int posr = r - m * br;
  int dem[30];
  memset(dem, 0, sizeof dem);
  vector<int> xl = turn(b[bl]);
  for (int i = posl; i < xl.size(); i++) {
    dem[xl[i]]++;
    c[bl][xl[i]]--;
  }
  vector<int> xr = turn(b[br]);
  for (int i = 0; i <= posr; i++) {
    dem[xr[i]]++;
    c[br][xr[i]]--;
  }
  for (int i = bl + 1; i < br; i++) {
    for (int j = 0; j < 30; j++) {
      dem[j] += c[i][j];
    }
  }
  int cur = 0;
  for (int i = posl; i < xl.size(); i++) {
    while (dem[cur] == 0) {
      cur++;
    }
    xl[i] = cur;
    c[bl][cur]++;
    dem[cur]--;
  }
  for (int i = bl + 1; i < br; i++) {
    int xx = m;
    memset(c[i], 0, sizeof c[i]);
    b[i].clear();
    while (xx) {
      while (dem[cur] == 0) {
        cur++;
      }
      if (dem[cur] >= xx) {
        c[i][cur] += xx;
        dem[cur] -= xx;
        b[i].push_back(pi(cur, xx));
        xx = 0;
      } else {
        xx -= dem[cur];
        c[i][cur] += dem[cur];
        b[i].push_back(pi(cur, dem[cur]));
        dem[cur] = 0;
        cur++;
      }
    }
  }
  for (int i = 0; i <= posr; i++) {
    while (dem[cur] == 0) {
      cur++;
    }
    xr[i] = cur;
    c[br][cur]++;
    dem[cur]--;
  }
  b[bl].clear();
  b[br].clear();
  for (int i = 0; i < xl.size(); i++) {
    b[bl].push_back(pi(xl[i], 1));
  }
  for (int i = 0; i < xr.size(); i++) {
    b[br].push_back(pi(xr[i], 1));
  }
}

void giam(int l, int r) {
  int bl = l / m;
  int br = r / m;
  if (bl == br) {
    vector <int> x = turn(b[bl]);
    b[bl].clear();
    int posl = l - m * bl;
    int posr = r - m * bl;
    sort(x.begin() + posl, x.begin() + posr + 1, greater<int>());
    for (int i = 0; i < x.size(); i++) {
      b[bl].push_back(pi(x[i], 1));
    }
    return;
  }
  int posl = l - m * bl;
  int posr = r - m * br;
  int dem[30];
  memset(dem, 0, sizeof dem);
  vector<int> xl = turn(b[bl]);
  for (int i = posl; i < xl.size(); i++) {
    dem[xl[i]]++;
    c[bl][xl[i]]--;
  }
  vector<int> xr = turn(b[br]);
  for (int i = 0; i <= posr; i++) {
    dem[xr[i]]++;
    c[br][xr[i]]--;
  }
  for (int i = bl + 1; i < br; i++) {
    for (int j = 0; j < 30; j++) {
      dem[j] += c[i][j];
    }
  }
  int cur = 29;
  for (int i = posl; i < xl.size(); i++) {
    while (dem[cur] == 0) {
      cur--;
    }
    xl[i] = cur;
    c[bl][cur]++;
    dem[cur]--;
  }
  for (int i = bl + 1; i < br; i++) {
    int xx = m;
    memset(c[i], 0, sizeof c[i]);
    b[i].clear();
    while (xx) {
      while (dem[cur] == 0) {
        cur--;
      }
      if (dem[cur] >= xx) {
        c[i][cur] += xx;
        dem[cur] -= xx;
        b[i].push_back(pi(cur, xx));
        xx = 0;
      } else {
        xx -= dem[cur];
        c[i][cur] += dem[cur];
        b[i].push_back(pi(cur, dem[cur]));
        dem[cur] = 0;
        cur--;
      }
    }
  }
  for (int i = 0; i <= posr; i++) {
    while (dem[cur] == 0) {
      cur--;
    }
    xr[i] = cur;
    c[br][cur]++;
    dem[cur]--;
  }
  b[bl].clear();
  b[br].clear();
  for (int i = 0; i < xl.size(); i++) {
    b[bl].push_back(pi(xl[i], 1));
  }
  for (int i = 0; i < xr.size(); i++) {
    b[br].push_back(pi(xr[i], 1));
  }
}

void out() {
  for (int i = 0; i <= sl; i++) {
    vector <int> x = turn(b[i]);
    for (int j = 0; j < x.size(); j++) {
      cout << (char)(x[j] + 'a');
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  cin >> a;
  m = sqrt(n);
  for (int i = 0; i < n; i++) {
    int x = i / m;
    sl = max(sl, x);
    b[x].push_back(pi(a[i] - 'a', 1));
    c[x][a[i] - 'a']++;
  }
  for (int i = 0; i < q; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    if (k) {
      tang(l, r);
    } else {
      giam(l, r);
    }
  }
  out();
  return 0;
}
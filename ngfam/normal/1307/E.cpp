#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 5005;

int v[maxn][maxn];

int add(int x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int mult(int x, int y) {
  return 1LL * x * y % mod;
}

int binpow(int x, int y) {
  int ret = 1;
  for(; y > 0; x = mult(x, x), y >>= 1) {
    if(y & 1) ret = mult(ret, x);
  }
  return ret;
}

int inverse_modulo(int x) {
  return binpow(x, mod - 2);
}

int comb(int x) {
  return x * (x - 1) / 2;
}

pair<int, int> calc(int x, int y) {
  if(x > y) swap(x, y);
  if(x == 0) {
    if(y == 0) return make_pair(0, 1);
    return make_pair(1, y);
  }

  if(x == 1 && y == 1) {
    return make_pair(1, 2);
  }

  int ret = 0;

  ret = add(ret, mult(2, comb(x)));
  ret = add(ret, mult(x, y - x));
  return make_pair(2, ret);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> a(n), c(n), d(n);
  for(int &x : a) {
    cin >> x, --x;
    c[x]++;
  }

  vector<vector<int>> cows(n);
  for(int i = 0; i < m; ++i) {
    int f, h; cin >> f >> h;
    cows[--f].emplace_back(h);
    ++v[f][h];
  }

  vector<int> pl(n), pr(n);
  for(int i = 0; i < n; ++i) {
    sort(cows[i].begin(), cows[i].end());
    pl[i] = 0;
    pr[i] = upper_bound(cows[i].begin(), cows[i].end(), c[i]) - cows[i].begin();
  }

  int best = 0;
  int totway = 1;


  for(int i = 0; i < n; ++i) {
    if(pr[i] > 0) {
      best++;
      totway = mult(totway, pr[i]);
    }
  }

  for(int i = 0; i < n; ++i) {
    int x = a[i];
    d[x]++;
    c[x]--;
    pl[x] = upper_bound(cows[x].begin(), cows[x].end(), d[x]) - cows[x].begin();
    pr[x] = upper_bound(cows[x].begin(), cows[x].end(), c[x]) - cows[x].begin();

    if(pl[x] - 1 >= cows[x].size() || cows[x][pl[x] - 1] != d[x]) continue;



    int tot = 0, way = 1;
    for(int j = 0; j < n; ++j)  {
      if(j == x) continue;
      auto p = calc(pl[j], pr[j]);
      tot += p.first;
      way = mult(way, p.second);

    }


    if(c[x] < d[x]) {
      tot += 1;
      way = mult(way, v[x][d[x]]);
      if(pr[x]) {
        tot += 1;
        way = mult(way, pr[x]);
      }
    }
    else {
      if(v[x][d[x]] == 1 && pr[x] == 1) {
        tot += 1;
      }
      else {
        tot += 2;
        int ret = 0;
        ret = add(ret, mult(2, comb(v[x][d[x]])));
        ret = add(ret, mult(v[x][d[x]], pr[x] - v[x][d[x]]));
        way = mult(way, ret);
      }
    }


    if(tot > best) {
      best = tot;
      totway = way;
    }
    else if(tot == best){
      totway = add(totway, way);
    }

  }

  cout << best << " " << totway << endl;

  return 0;
}
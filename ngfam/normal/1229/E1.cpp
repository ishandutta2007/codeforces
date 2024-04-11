#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

const int N = 1 << 20;

int fpow(int x, int y) {
  int ret = 1;
  while(y) {
    if(y & 1) ret = (1LL * ret * x) % mod;
    x = (1LL * x * x) % mod;
    y >>= 1;
  }
  return ret;
}

const int M = 21;

int n;
int f[N], g[N];
int p[M][M];

int idx[2][N];
int rev[N];
int matched[M];
int adj[M][M];

void work(int *f, vector < int > l, vector < int > r, vector < int > subgraph, int *idx) {

  vector < pair < int, int > > edges;
  for(int x : l) {
    for(int y : r) {
      edges.emplace_back(x, y);
    }
  }

  for(int mask = 0; mask < (1 << edges.size()); ++mask) {
    int rate = 1;
    int newmask = 0;
    for(int i = 0; i < edges.size(); ++i) {
      if(mask & (1 << i)) {
        rate = (1LL * rate * p[edges[i].first][edges[i].second]) % mod;
        adj[edges[i].first][edges[i].second] = 1;
      }
      else {
        rate = (1LL * rate * (1 - p[edges[i].first][edges[i].second])) % mod;
        adj[edges[i].first][edges[i].second] = 0;
      }
      rate = (rate + mod) % mod;
    }

    for(int gr : subgraph) {
      vector < int > perm, indices;
      for(int x : l) perm.push_back(x);
      for(int i = 0; i < n; ++i) if(gr & (1 << i)) {
        indices.push_back(i + n);
      }

      bool flag = false;
      do{
        bool ok  = true;
        for(int i = 0; i < perm.size(); ++i){
          if(!adj[perm[i]][indices[i]]) ok = false;
        }
        if(ok) {
          flag = true;
          break;
        }
      }
      while(next_permutation(indices.begin(), indices.end()));
      if(flag) newmask |= (1 << idx[gr]);
    }
    f[newmask] += rate;
    f[newmask] %= mod;
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> p[i][j + n];
      p[i][j + n] = (1LL * p[i][j + n] * fpow(100, mod - 2)) % mod;
    }
  }

  if(n == 1) {
    cout << p[0][1];
    return 0;
  }

  int m1 = n / 2;
  int m2 = n - m1;

  int cnt = 0, cnt2 = 0;
  vector < int > sub1, sub2;
  for(int mask = 0; mask < (1 << n); ++mask) {
    if(__builtin_popcount(mask) == m1) {
      idx[0][mask] = cnt++;
      sub1.push_back(mask);
    }
    if(__builtin_popcount(mask) == m2) {
      idx[1][mask] = cnt2++;
      sub2.push_back(mask);
    }
  }

  for(int i = 0; i < sub2.size(); ++i) {
    int mask = sub2[i];
    for(int bigmask = 0; bigmask < (1 << cnt2); ++bigmask) {
      if(bigmask & (1 << i)) rev[bigmask] |= (1 << idx[0][(1 << n) - 1 - mask]);
    }
  }

  vector < int > l1, l2;
  vector < int > r;
  for(int i = n; i < n + n; ++i) {
    r.push_back(i);
  }

  for(int i = 0; i < m1; ++i) l1.push_back(i);
  for(int i = m1; i < n; ++i) l2.push_back(i);

  work(f, l1, r, sub1, idx[0]);
  work(g, l2, r, sub2, idx[1]);



  for(int i = 0; i < cnt; ++i) {
    for(int mask = 0; mask < (1 << cnt); ++mask) {
      if(mask & (1 << i)) {
        f[mask] += f[mask ^ (1 << i)];
        f[mask] %= mod;
      }
    }
  }

  long long ans = 0;

  for(int mask = 1; mask < (1 << cnt2); ++mask) {
    int w = (1 - f[(1 << cnt) - 1 - rev[mask]] + mod) % mod;
//    cout << mask << " " << rev[mask] << " " << w << " " << g[mask] << endl;
    ans += 1LL * w * g[mask] % mod;
    ans %= mod;
  }

  cout << ans;

  return 0;
}



/// moi mask,
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 515;
const long long mod = 998244353;

int n, m;
int a[1000005];
int lab[1000005];
long long dp[N][N];

int find(int x) {
  if(lab[x] < 0) return x;
  return lab[x] = find(lab[x]);
}

void join(int x, int y) {
  x = find(x); y = find(y);
  if(x != y) lab[x] = y;
}


void merge(vector < int > &f, int id) {
  id = a[id];
  for(int j = 0; j <= n; ++j) {
    f[j] = dp[id][j];
  }
  for(int k = 0; k <= n; ++k) dp[id][k] = 0;
} 

main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  memset(lab, -1, sizeof lab);

  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> a[i];
  }

  for(int i = n; i >= 1; --i) {
    int l = 0, r;
    for(int id = 1; id <= m; ++id) {
      if(a[id] == i && l == 0) {
        l = id;
      }
      if(a[id] == i) r = id;
    }

    for(int id = l; id <= r; ++id) {
      if(a[id] < i) {
        cout << 0;
        return 0;
      }
    }

    long long mul = 1;
    for(int id = l; id < r; ++id) {
      if(find(id + 1) != find(id)) {
        long long tot = 0, w = find(id + 1);
        w = a[w];
        for(int k = 0; k <= n + 4; ++k) {
          tot += dp[w][k];
          tot %= mod;
          dp[w][k] = 0;
        }
        tot = max(tot, 1LL);
        mul *= tot;
        mul %= mod;
      }
      join(id, id + 1);
    }

    vector < int > f(n + 5, 0), g(n + 5, 0);

    f[0] = g[0] = 1;
    if(a[l - 1] > i) {
      merge(f, find(l - 1));
      join(l, l - 1);
    }
    if(a[r + 1] > i) {
      merge(g, find(r + 1));
      join(r, r + 1);
    }

    for(int i = n + 3; i >= 0; --i) {
      f[i] += f[i + 1];
      g[i] += g[i + 1];
      f[i] %= mod;
      g[i] %= mod;
    }

   // cout << i << " " << f << " " << g << endl;

    int newid = find(l);
    newid = a[newid];
    //cout << i << " " << f << " " << g << " " << newid << endl;
    for(int i = 0; i <= n + 4; ++i) {
      for(int j = 0; j + i <= n; ++j) {
        dp[newid][i + j + 1] += f[i] * g[j], dp[newid][i + j + 1] %= mod;
      }
    }

    for(int i = 0; i <= n + 4; ++i) {
      dp[newid][i] *= mul;
      dp[newid][i] %= mod;
    }
  }

  int res = 0;
  for(int i = 1; i <= n; ++i) {
    res += dp[a[find(1)]][i];
    res %= mod;
  }

  cout << res;

  return 0;
}
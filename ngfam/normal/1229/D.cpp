#include <bits/stdc++.h>

using namespace std;

const int N = 400020;

int n, k;
int edge[222][122];
vector < vector < int > > perm;
map < vector < int >, int > mvec;

int a[N];
int id[N];
int dp[122];

int sz[8];
int qu[8][1055];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> k;
  vector < int > w;
  for(int i = 1; i <= k; ++i) w.push_back(i - 1);

  int cnt = 0;
  do{
    mvec[w] = cnt++;
    perm.push_back(w);
  } while(next_permutation(w.begin(), w.end()));

  for(int i = 0; i < perm.size(); ++i) {
    for(int j = 0; j < perm.size(); ++j) {
      vector < int > t = perm[i];
      for(int s = 0; s < k; ++s) t[perm[j][s]] = perm[i][s];
      edge[i][j] = mvec[t];
    }
  }

  for(int i = 1; i <= n; ++i) {
    vector < int > w(k);
    for(int &x : w) cin >> x, x--;
    a[i] = mvec[w];
    assert(a[i] < 120);
  }

  memset(dp, -1, sizeof dp);

  vector < int > basic;

  long long ans = 0;

  for(int i = 1; i <= n; ++i) {
    basic.push_back(i);
    sort(basic.rbegin(), basic.rend());
    for(int j = 0; j < basic.size(); ++j) id[basic[j]] = j;
    for(int j = 0; j < perm.size(); ++j) if(dp[j] != -1) {
      dp[j]++;
      assert(dp[j] < basic.size());
    }
    dp[0] = 0;

    for(int t = 0; t < perm.size(); ++t) {
      if(dp[t] != -1) qu[dp[t]][sz[dp[t]]++] = t;
    }

    for(int j = 0; j < basic.size(); ++j) {
      while(sz[j] > 0) {
        int x = qu[j][--sz[j]];
        if(dp[x] != j) continue;
        for(int k = 0; k <= dp[x]; ++k) {
          int nxt = edge[x][a[basic[k]]];
          if(dp[nxt] > dp[x] || dp[nxt] == -1) {
            dp[nxt] = dp[x];
            qu[dp[nxt]][sz[dp[nxt]]++] = nxt;
          }
        }
      }
    }

    for(int j = 0; j < perm.size(); ++j) {
      if(dp[j] != -1) {
        id[basic[dp[j]]] = -1;
        ans += basic[dp[j]];
      }
    }


    vector < int > temp;
    int cntid = 0;
    for(int x : basic) if(id[x] == -1) {
      temp.push_back(x);
      id[x] = cntid++;
    }

    for(int j = 0; j < perm.size(); ++j) if(dp[j] != -1) dp[j] = id[basic[dp[j]]];

    basic = temp;
  }

  cout << ans << endl;

  return 0;
}
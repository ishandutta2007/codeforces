#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
const int BIT = 18;

int rmq[BIT][N];
int a[N];

int lg[N];

int ask(int l, int r){
  int sz = r-l+1;
  int pp = lg[sz];
  int ai = rmq[pp][l];
  int bi = rmq[pp][r - (1 << pp) + 1];
  if(a[ai] > a[bi])
    return ai;
  else
    return bi;
}

ll dp[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i < n;i ++ ){
    cin >> a[i];
    rmq[0][i] = i;
  }
  a[n] = n;
  int p = 0;
  int z = 1;
  for(int j = 1;j <= n;j ++ ){
    if(j > z*2)
      p ++ ,z *= 2;
    lg[j] = p;
  }
  dp[n-1] = 1;
  int tl, tr;
  for(int i = 1;i < BIT;i ++ ){
    for(int j = 1;j <= n;j ++ ){
      if((1 << i) + j - 1 <= n){
        tl = rmq[i-1][j];
        tr = rmq[i-1][j+(1<<(i-1))];
        if(a[tl] >= a[tr])
          rmq[i][j] = tl;
        else
          rmq[i][j] = tr;
      }
    }
  }
  int d;
  ll ans = 1LL;
  for(int x = n-2; x >= 1; x -- ){
    d = ask(x + 1, a[x]);
    dp[x] = dp[d] + n-a[x]+1;
    dp[x] -= a[x] - d + 1;
    dp[x] += a[x] - x;
    ans += dp[x];
  }
  cout << ans << "\n";
  return 0;
}
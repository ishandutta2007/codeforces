#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
const int MOD = 998244353;

int l[N], r[N], x[N];

int mult(int a, int b){ 
  return (a * 1ll * b) % MOD;
}

int cnt[N];
int need[N];
int dp[N];
int prf[N];

int add(int a, int b){
  a += b;
  if(a < 0)
    a += MOD;
  else if(a >= MOD)
    a -= MOD;
  return a;
}

int ask(int l, int r){
  if(l==0)return prf[r];
  else return add(prf[r],-prf[l-1]);
}

int main(){
  fastIO;
  int n, k, m;
  cin >> n >> k >> m;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> l[i] >> r[i] >> x[i];
  }
  int res = 1;
  for(int bit = 0 ; bit < k; bit ++  ){
    for(int i = 0; i <= n+1; i ++ ){
      cnt[i]=0;
      dp[i]=0;
      prf[i]=0;
    }
    for(int i = 0 ; i <= n; i ++ ){
      need[i]=0;
    }
    for(int i = 0 ; i < m ; i ++ ){
      if((x[i] & (1 << bit))){
        cnt[l[i]]++;
        cnt[r[i]+1]--;
      }
      else{
        need[r[i]]=max(need[r[i]],l[i]);
      }
    }
    for(int i = 1; i <= n; i ++ ){
      need[i]=max(need[i],need[i-1]);
    }
    for(int i = 1; i <= n+1; i ++ )
      cnt[i]+=cnt[i-1];
    dp[0]=1;
    prf[0]=1;
    for(int i = 1; i <= n+1; i ++ ){
      if(cnt[i] == 0){
        dp[i]=add(dp[i],ask(need[i-1],i-1));
      }
      prf[i]=(prf[i]+prf[i-1])%MOD;
      prf[i]=(prf[i]+dp[i])%MOD;
    }
    res = (res * 1ll * dp[n + 1]) % MOD;
  }
  cout << res << "\n";
  return 0;
}
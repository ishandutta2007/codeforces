#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 9;
const int MOD = (int)1e9 + 7;
int fac[N];
int inv[N];

int powr(int n, int k){
  if(k == 0) return 1;
  int p = powr(n,k/2);
  p = (p * 1ll * p) % MOD;
  if(k % 2 == 1) p = (p * 1ll * n) % MOD;
  return p;
}

void add(int &a, int b){
  a += b;
  if(a < 0) a += MOD;
  else if(a >= MOD) a -= MOD;
}

int ncr(int n, int k){  
  return (((fac[n]*1ll*inv[k])%MOD)*1ll*inv[n-k])%MOD;
}

int main(){
  fastIO;
  fac[0]=1;
  inv[0] = 1;
  for(int i = 1; i < N ; i ++ ){
    fac[i] = (i * 1ll * fac[i - 1]) % MOD;
    inv[i] = powr(fac[i], MOD-2);
  }
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i = 0 ; i < n; i ++ ){
    cin >> t[i];
  }
  int sign = +1;
  while(n > 1){
    if(n % 2 == 0 && sign == +1) break;
    for(int i = 0 ; i + 1 < n; i ++ ){
      add(t[i],sign * t[i + 1]);
      sign *= -1;
    }
    t.pop_back();
    n--;
  }
  if(n == 1){
    cout << t[0] << "\n";
    return 0;
  }
  int k = (n-1)/2;
  vector<int> cc;
  int x;
  for(int i = 0 ; i <= k; i ++ ){
    x = ncr(k,i);
    cc.push_back(x);
    if(n % 4 == 0){
      x = (MOD-x)%MOD;
      cc.push_back(x);
    }
    else{
      cc.push_back(x);
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n; i ++ ){
    add(ans,(t[i]*1ll*cc[i])%MOD);
  }
  cout << ans << "\n";
  return 0;
}
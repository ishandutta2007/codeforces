#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n + 1), pf(n + 1), f(k);
  for(int i = 1 ; i <= n ;i ++ )
    cin >> a[i];
  sort(a.begin(), a.end());
  pf[0]=0;
  for(int i = 1; i <= n; i ++ )
    pf[i]=a[i]+pf[i-1];
  int res = 0;
  for(int i = 1; i <= n; i ++ ){
    if(i>=k)
      f[i%k] += a[i];
    if(f[i%k]+pf[i%k] <= p)
      res=i;
  }
  cout << res << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t =0 ; t < tc; t ++ )
    solve();
  return 0;
}
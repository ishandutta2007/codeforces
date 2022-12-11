#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n;
  cin >> n;
  ll a[n * 2];
  ll x, y;
  for(int i = 0;i < n*2;i ++ ){
    cin >> a[i];
  }
  sort(a, a + (n * 2));
  ll ans = (ll)2e18;
  for(int i = 0;i <= n;i ++ ){
    x = a[i + n - 1] - a[i];
    if(i == n)
      y = a[i - 1] - a[0];
    else if(i == 0)
      y = a[2*n-1] - a[n];
    else
      y = a[2*n-1] - a[0];
    ans = min(ans, x * y);
  }
  cout << ans;
  return 0;
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
map<ll, int> las;
ll a[N];
ll can[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  ll pf = 0;
  las[0] = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    pf += a[i];
    can[i] = n+1;
    if(las.count(pf)){
      can[las[pf]+1] = i;
    }
    las[pf] = i;
  }
  can[n+1] = n + 1;
  ll ans = 0;
  for(int i = n; i >= 1; i -- ){
    can[i]=min(can[i],can[i+1]);
    ans += can[i]-i;
  }
  cout << ans;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

int main(){
  fastIO;
  ll a, b;
  cin >> a >> b;
  vector<ll> blue, red;
  for(ll i = 1; i * i <= a; i ++ ){
    if(a % i == 0)
      blue.push_back(i);
  }
  for(ll i = 1;i * i <= b; i ++ ){
    if(b % i == 0)
      red.push_back(i);
  }
  ll tot = a + b;
  ll shortest, longest;
  ll fir, sec;
  int ix;
  ll ans = (ll)1e18;
  for(ll i = 1; i * i <= tot; i ++ ){
    if(tot % i != 0)
      continue;
    shortest = i;
    longest = tot/i;
    ix = upper_bound(blue.begin(), blue.end(), shortest) - blue.begin();
    -- ix;
    fir = blue[ix];
    sec = a / fir;
    if(fir <= shortest and sec <= longest)
      ans = min(ans, (shortest + longest) * 2);
    /* -!----------!- */
    ix = upper_bound(red.begin(), red.end(), shortest) - red.begin();
    -- ix;
    fir = red[ix];
    sec = b / fir;
    if(fir <= shortest and sec <= longest)
      ans = min(ans, (shortest + longest) * 2);  
  }
  cout << ans << "\n";
  return 0;
}
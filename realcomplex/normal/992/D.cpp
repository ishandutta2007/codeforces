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

const ll MAX = (ll)4e18;

int main(){
  fastIO;
  int n;
  ll k;
  cin >> n >> k;
  ll a[n];
  set<int> pos;
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
    if(i == n-1 or a[i] != 1ll)pos.insert(i);
  }
  ll p, s;
  ll ans = 0ll;
  int las;
  int cur;
  ll rem;
  ll dd;
  for(int i = 0;i < n;i ++ ){
    p = a[i];
    s = a[i];
    las = i;
    if(p % s == 0 and p/s == k)
      ans ++ ;
    auto nx = pos.upper_bound(i);
    while(nx != pos.end()){
      cur = *nx;
      rem = cur - las - 1;
      if(cur - las > 1 and p % k == 0){
        dd = p/k;
        if(s < dd and s + rem >= dd)
          ans ++ ;
      }
      s += rem;
      if(MAX / p >= a[cur]){
        p *= a[cur];
        s += a[cur];
        if(p % s == 0 and p/s == k)
          ans ++ ;
      }
      else{
        break;
      }
      las = cur;
      ++nx;
    }
  }
  cout << ans << "\n"; 
  return 0;
}
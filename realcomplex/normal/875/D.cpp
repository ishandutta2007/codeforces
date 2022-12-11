#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 11;
int a[N];
int c[N];
ll ans = 0;

struct S{ 
  int OR;
  int sz;
  int bad;
};

void solve(int l, int r){ // n (log max)^2 kinda cheesy but should work
  if(l >= r){
    return;
  }
  int mid = (l + r) / 2;  
  ans += (r - mid) * 1ll * (mid - l + 1);
  vector<S> ri;
  int orr = 0;
  int el = 0;
  int shit = 0;
  bool good = true;
  for(int i = mid + 1; i <= r;  i ++ ){
    if((orr | a[i]) > orr){
      if(el > 0) ri.push_back({orr, el, shit});
      orr |= a[i];
      el = 0;
      shit = 0;
      good = true;
    }
    el ++ ;
    if(a[i] == orr) good = false;
    if(!good) shit ++ ;
  }
  ri.push_back({orr, el, shit});
  orr = 0;
  el = 0;
  shit = 0;
  good = true;
  vector<S> li;
  for(int i = mid ; i >= l ; i -- ){
    if((orr | a[i]) > orr){
      if(el > 0) li.push_back({orr, el, shit});
      orr |= a[i];
      el = 0;
      shit = 0;
      good = true;
    }
    el ++ ;
    if(a[i] == orr) good = false;
    if(!good) shit ++ ;
  }
  li.push_back({orr, el, shit});
  for(auto x : li){
    for(auto y : ri){
      if((x.OR | y.OR) == x.OR && (x.OR | y.OR) == y.OR){
        ans -= x.bad * 1ll * y.sz;
        ans -= x.sz * 1ll * y.bad;
        ans += x.bad * 1ll * y.bad;
      }
      else if((x.OR | y.OR) == x.OR){
        ans -= x.bad * 1ll * y.sz;
      }
      else if((x.OR | y.OR) == y.OR){
        ans -= x.sz * 1ll * y.bad;
      }
    }
  }
  solve(l, mid);
  solve(mid + 1, r);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n; i ++ ){
    cin >> a[i];
    c[i] = __builtin_popcount(a[i]);
    //cout << c[i] << "\n";
  }
  solve(0, n-1);
  cout << ans;
  return 0;
}
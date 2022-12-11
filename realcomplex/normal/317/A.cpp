#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll x,y,m;
  cin >> x >> y >> m;
  if(x>y)swap(x,y);
  ll ans = 0;
  ll w;
  ll op;
  for(int i = 0;i<(int)1e6 + 9;i++){
    if(y>=m){
      cout << ans << "\n";
      return 0;
    } 
    if(y<=0){
      cout << -1 << "\n";
      return 0; 
    }
    w=y-x;
    op=0;
    op+=w/y;
    if(w%y!=0)op++;
    op=max(1LL,op);
    x+=op*y;
    ans+=op;
    swap(x,y);
  }
  return 0;
}
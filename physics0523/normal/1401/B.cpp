#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c;
    int p,q,r;
    cin >> a >> b >> c;
    cin >> p >> q >> r;
    int res=0;
    int dlt=min(c,q);
    c-=dlt;q-=dlt;
    res+=2*dlt;
    dlt=max(0,(b+r)-(a+b+c));
    cout << res-2*dlt << '\n';
  }
  return 0;
}
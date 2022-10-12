#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int xa,ya;
    cin >> xa >> ya;
    int xb,yb;
    cin >> xb >> yb;
    int xf,yf;
    cin >> xf >> yf;
    int res=abs(xa-xb)+abs(ya-yb);
    if(xa==xb && xa==xf && min(ya,yb)<=yf && yf<=max(ya,yb)){res+=2;}
    if(ya==yb && ya==yf && min(xa,xb)<=xf && xf<=max(xa,xb)){res+=2;}
    cout << res << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long w,h;
    long long x1,x2,y1,y2;
    cin >> w >> h;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    long long ww,hh;
    cin >> ww >> hh;
    long long sw=(x2-x1)+ww;
    long long sh=(y2-y1)+hh;
    if(sw>w && sh>h){cout << "-1\n";continue;}
    long long res=(1ll<<50);
    if(sw<=w){
      long long lw,up;
      lw=x1;
      up=w-x2;
      //cout << lw << ' ' << up << '\n';
      res=min(max(0ll,min(ww-lw,ww-up)),res);
    }
    if(sh<=h){
      long long lw,up;
      lw=y1;
      up=h-y2;
      //cout << lw << ' ' << up << '\n';
      res=min(max(0ll,min(hh-lw,hh-up)),res);
    }
    cout << res << ".0000000000\n";
  }
  return 0;
}
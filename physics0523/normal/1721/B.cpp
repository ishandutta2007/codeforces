#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,sx,sy,d;
    cin >> n >> m >> sx >> sy >> d;
    int res=-1;
    if(abs(sy-1)>d && abs(sx-n)>d){res=n+m-2;}
    if(abs(sx-1)>d && abs(sy-m)>d){res=n+m-2;}
    cout << res << "\n";
  }
  return 0;
}
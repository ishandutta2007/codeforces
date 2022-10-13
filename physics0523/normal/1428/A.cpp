#include<bits/stdc++.h>

using namespace std;
int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    int pn=0;
    if(sx!=gx){pn++;}
    if(sy!=gy){pn++;}
    int res=0;
    res+=max(gx,sx)-min(gx,sx);
    res+=max(gy,sy)-min(gy,sy);
    if(pn==2){res+=2;}
    cout << res << '\n';
  }
  return 0;
}
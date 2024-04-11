#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,u,r,d,l;
    cin >> n >> u >> r >> d >> l;
    bool fl=false;
    for(int i=0;i<16;i++){
      int tu=u,tr=r,td=d,tl=l;
      if(i&1){tu--;tr--;}
      if(i&2){tr--;td--;}
      if(i&4){td--;tl--;}
      if(i&8){tl--;tu--;}
      if(
        0<=tu && tu<=(n-2) &&
        0<=tr && tr<=(n-2) &&
        0<=td && td<=(n-2) &&
        0<=tl && tl<=(n-2)
      ){fl=true;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
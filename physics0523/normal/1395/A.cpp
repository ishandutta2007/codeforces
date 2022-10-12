#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int r,g,b,w;
    cin >> r >> g >> b >> w;
    bool fl=false;
    for(int i=0;i<2;i++){
      if((r%2)+(g%2)+(b%2)+(w%2)<=1){fl=true;}
      if(r==0 || g==0 || b==0){break;}
      r--;g--;b--;w+=3;
    }
    if(fl){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}
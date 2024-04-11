#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int res=10;
    for(int i=0;i<(1<<10);i++){
      bool fl=false;
      for(int j=0;j<10;j++){
        int v;
        if(i&(1<<j)){v=1;}else{v=0;}
        if(s[j]=='0' && v==1){fl=true;break;}
        if(s[j]=='1' && v==0){fl=true;break;}
      }
      if(fl){continue;}
      int as=0,bs=0,am=5,bm=5;
      for(int j=0;j<10;j++){
        int v;
        if(i&(1<<j)){v=1;}else{v=0;}
        if(j%2==0){
          if(v==1){as++;}
          else{am--;}
        }
        else{
          if(v==1){bs++;}
          else{bm--;}
        }
        if(as>bm || bs>am){res=min(j+1,res);}
      }
    }
    cout << res << '\n';
  }
  return 0;
}
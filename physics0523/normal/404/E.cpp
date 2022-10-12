#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  if(s.back()=='R'){
    for(auto &nx : s){
      nx=('L'+'R'-nx);
    }
  }
  int l=s.size();
  // block * 0
  {
    int mi=0,h=0;
    for(int i=0;i<l;i++){
      if(s[i]=='L'){h--;}
      else{h++;}
      if(mi>h){
        mi=h;
        if(i==l-1){
          cout << "1\n";
          return 0;
        }
      }
    }
  }
  // block * 1
  int st=1,fi=1048576;
  while(st<=fi){
    int te=(st+fi)/2;
    bool isok=false;

    int mi=0,h=0;
    for(int i=0;i<l;i++){
      if(s[i]=='L'){h--;}
      else{h++;}
      h=min(h,te-1);
      if(mi>h){
        mi=h;
        if(i==l-1){isok=true;}
      }
    }

    if(isok){st=te+1;}
    else{fi=te-1;}
  }
  cout << fi << '\n';
  return 0;
}
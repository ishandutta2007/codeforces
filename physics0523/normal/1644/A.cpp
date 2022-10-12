#include<bits/stdc++.h>

using namespace std;

int cvrt(char c){
  if(c=='r'){return 1;}
  if(c=='g'){return 2;}
  if(c=='b'){return 3;}
  if(c=='R'){return -1;}
  if(c=='G'){return -2;}
  if(c=='B'){return -3;}
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    bool isok=true;
    int fl=0;
    for(auto &nx : s){
      int v=cvrt(nx);
      if(v>0){
        fl|=(1<<v);
      }
      else{
        v*=-1;
        if((fl&(1<<v))==0){isok=false;}
      }
    }
    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool isok(int x){
  int st=0,fi=1000;
  while(st<=fi){
    int te=(st+fi);
    if(te*te==x){return true;}
    if(te*te<x){st=te+1;}
    else{fi=te-1;}
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int x,y;
    cin >> x >> y;
    if(x==0 && y==0){cout << "0\n";}
    else if(isok(x*x+y*y)){cout << "1\n";}
    else{cout << "2\n";}
  }
  return 0;
}
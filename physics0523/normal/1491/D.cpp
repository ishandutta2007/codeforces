#include<bits/stdc++.h>

using namespace std;

int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}

int jud(int i,int j){
  if(i<=j && dsumb(i,2)>=dsumb(j,2)){
    int ip=0,jp=0,fl=1;
    while(i>0 || j>0){
      ip+=(i%2);
      jp+=(j%2);
      if(ip<jp){fl=0;}
      i/=2;
      j/=2;
    }
    return fl;
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int i,j;
    cin >> i >> j;
    if(jud(i,j)){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
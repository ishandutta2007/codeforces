#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k,r,c;
    cin >> n >> k >> r >> c;
    r--;c--;
    int tg=(r+c)%k;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((i+j)%k==tg){cout << "X";}
        else{cout << ".";}
      }
      cout << "\n";
    }
  }
  return 0;
}
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n0,n1,n2;
    cin >> n0 >> n1 >> n2;
    int fir,sec;
    if(n0>n2){
      for(int i=0;i<=n1;i++){
        int tg=(i%2);
        cout << tg;
        while(n0>0 && tg==0){cout << tg;n0--;}
        while(n2>0 && tg==1){cout << tg;n2--;}
      }
    }
    else{
      for(int i=0;i<=n1;i++){
        int tg=1-(i%2);
        cout << tg;
        while(n0>0 && tg==0){cout << tg;n0--;}
        while(n2>0 && tg==1){cout << tg;n2--;}
      }
    }
    cout << '\n';
  }
  return 0;
}
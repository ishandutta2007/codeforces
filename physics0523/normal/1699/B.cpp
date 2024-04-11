#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(j){cout << ' ';}
        int kind=((i/2)+(j/2))%2;
        if(kind%2){
          if((i%2)==(j%2)){cout << "1";}
          else{cout << "0";}
        }
        else{
          if((i%2)!=(j%2)){cout << "1";}
          else{cout << "0";}
        }
      }cout << '\n';
    }
  }
  return 0;
}
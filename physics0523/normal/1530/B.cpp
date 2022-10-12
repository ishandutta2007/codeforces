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
        if(1<=i && i<=n-2 && 1<=j && j<=m-2){cout << 0;continue;}
        if(n<m){
          if(i==0 || i==n-1){
            if(j%2==0){cout << 1;}else{cout << 0;}
          }
          else if(i%2==0 && i!=n-2){cout << 1;}
          else{cout << 0;}
        }
        else{
          if(j==0 || j==m-1){
            if(i%2==0){cout << 1;}else{cout << 0;}
          }
          else if(j%2==0 && j!=m-2){cout << 1;}
          else{cout << 0;}
        }
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}
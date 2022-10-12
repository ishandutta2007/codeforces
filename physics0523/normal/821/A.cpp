#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n));
  vector<vector<bool>> fl(n,vector<bool>(n,false));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){cin >> a[i][j];}
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
          if(a[i][l]==a[i][j]+a[k][l]){fl[i][l]=true;}
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]!=1 && !fl[i][j]){
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
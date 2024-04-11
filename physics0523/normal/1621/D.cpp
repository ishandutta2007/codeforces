#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<vector<long long>> c(2*n,vector<long long>(2*n));
    long long res=0;
    for(int i=0;i<2*n;i++){
      for(int j=0;j<2*n;j++){
        cin >> c[i][j];
        if(0<=i && i<n && 0<=j && j<n){res+=c[i][j];}
        if(n<=i && i<2*n && n<=j && j<2*n){res+=c[i][j];}
      }
    }
    long long del=2e9;
    del=min(c[n][0],del);
    del=min(c[2*n-1][0],del);
    del=min(c[n][n-1],del);
    del=min(c[2*n-1][n-1],del);

    del=min(c[0][n],del);
    del=min(c[0][2*n-1],del);
    del=min(c[n-1][n],del);
    del=min(c[n-1][2*n-1],del);
    cout << res+del << '\n';
  }
  return 0;
}
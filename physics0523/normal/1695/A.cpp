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
    int mxm=-2e9;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> a[i][j];
        mxm=max(mxm,a[i][j]);
      }
    }
    int res=n*m;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(a[i][j]==mxm){
          res=max(i+1,n-i)*max(j+1,m-j);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
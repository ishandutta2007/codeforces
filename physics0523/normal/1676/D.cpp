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
    vector<vector<long long>> a(n,vector<long long>(m,0));
    map<long long,long long> f,g;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> a[i][j];
        f[i+j]+=a[i][j];
        g[i-j]+=a[i][j];
      }
    }
    long long res=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        res=max(res,f[i+j]+g[i-j]-a[i][j]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
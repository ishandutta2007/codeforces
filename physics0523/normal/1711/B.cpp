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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<int> deg(n);
    vector<int> u(m),v(m);
    for(int i=0;i<m;i++){
      cin >> u[i] >> v[i];
      u[i]--;v[i]--;
      deg[u[i]]++;
      deg[v[i]]++;
    }
    if(m%2==0){
      cout << 0 << "\n";
      continue;
    }
    int res=1e9;
    for(int i=0;i<n;i++){
      if(deg[i]%2){res=min(res,a[i]);}
    }
    for(int i=0;i<m;i++){
      if(deg[u[i]]%2==0 && deg[v[i]]%2==0){
        res=min(res,a[u[i]]+a[v[i]]);
      }
    }
    cout << res << "\n";
  }
  return 0;
}
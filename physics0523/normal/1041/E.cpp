#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> bk(n+1,0);
  vector<int> rem;
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    if(u>v){swap(u,v);}
    if(v!=n){cout << "NO\n";return 0;}
    if(u==v){cout << "NO\n";return 0;}
    bk[u]++;
  }

  for(int i=1;i<n;i++){
    if(bk[i]==0){rem.push_back(i);}
  }
  vector<vector<int>> mem(n+1,vector<int>(0));
  for(int i=n-1;i>=1;i--){
    if(bk[i]>=1){
      mem[i].push_back(i);
    }
    for(int j=2;j<=bk[i];j++){
      // cerr << i << ' ' << rem.back() << '\n';
      if(i<rem.back()){
        cout << "NO\n";
        return 0;
      }
      mem[i].push_back(rem.back());
      rem.pop_back();
    }
  }
  cout << "YES\n";
  for(int i=1;i<=n;i++){
    sort(mem[i].begin(),mem[i].end());
    int prev=n;
    for(auto &nx : mem[i]){
      cout << prev << ' ' << nx << '\n';
      prev=nx;
    }
  }
  return 0;
}
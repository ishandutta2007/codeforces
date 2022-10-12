#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  long long res=0;
  vector<vector<long long>> h(100005);
  vector<vector<long long>> w(100005);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int c;
      cin >> c;
      h[c].push_back(i);
      w[c].push_back(j);
    }
  }

  for(auto &nx : h){
    sort(nx.begin(),nx.end());
    long long l=nx.size();
    long long sig=0;
    for(long long i=0;i<l;i++){
      res+=(i*nx[i]-sig);
      sig+=nx[i];
    }
  }
  for(auto &nx : w){
    sort(nx.begin(),nx.end());
    long long l=nx.size();
    long long sig=0;
    for(long long i=0;i<l;i++){
      res+=(i*nx[i]-sig);
      sig+=nx[i];
    }
  }

  cout << res << '\n';
  return 0;
}
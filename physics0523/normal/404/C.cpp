#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  vector<vector<long long>> mem(n);
  for(long long i=1;i<=n;i++){
    long long v;
    cin >> v;
    mem[v].push_back(i);
  }
  if(mem[0].size()!=1){cout << "-1\n";return 0;}
  vector<pair<long long,long long>> res;
  for(long long i=1;i<n;i++){
    long long ce;
    if(i==1){ce=k;}
    else{ce=k-1;}

    long long x=mem[i-1].size();
    long long y=mem[i].size();
    if(x*ce<y){cout << "-1\n";return 0;}
    for(long long j=0;j<y;j++){
      res.push_back({mem[i-1][j/ce],mem[i][j]});
    }
  }
  cout << res.size() << '\n';
  for(auto &nx : res){
    cout << nx.first << ' ';
    cout << nx.second << '\n';
  }
  return 0;
}
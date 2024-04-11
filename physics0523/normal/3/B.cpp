#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,v;
  cin >> n >> v;
  vector<vector<pi>> mem(3);
  int sig=0;
  for(int i=1;i<=n;i++){
    int t,p;
    cin >> t >> p;
    sig+=t;
    mem[t].push_back({p,i});
  }
  v=min(v,sig);

  sort(mem[1].begin(),mem[1].end());
  reverse(mem[1].begin(),mem[1].end());
  sort(mem[2].begin(),mem[2].end());
  reverse(mem[2].begin(),mem[2].end());

  int p1,p2;
  p2=min(v/2,(int)mem[2].size());
  v-=2*p2;
  p1=min(v,(int)mem[1].size());
  mem[1].push_back({0,-1});
  mem[1].push_back({0,-1});
  mem[1].push_back({0,-1});
  mem[1].push_back({0,-1});
  mem[1].push_back({0,-1});
  mem[2].push_back({0,-1});
  mem[2].push_back({0,-1});
  mem[2].push_back({0,-1});
  mem[2].push_back({0,-1});
  mem[2].push_back({0,-1});

  while(p2>0){
    int del=-mem[2][p2-1].first;
    del+=mem[1][p1].first;
    del+=mem[1][p1+1].first;
    if(del<0){break;}
    p2--;p1+=2;
  }

  int res=0;
  vector<int> rv;
  for(int i=0;i<p1;i++){
    res+=mem[1][i].first;
    if(mem[1][i].second>0){rv.push_back(mem[1][i].second);}
  }
  for(int i=0;i<p2;i++){
    res+=mem[2][i].first;
    if(mem[2][i].second>0){rv.push_back(mem[2][i].second);}
  }
  cout << res << '\n';
  for(int i=0;i<rv.size();i++){
    if(i){cout << ' ';}
    cout << rv[i];
  }cout << '\n';
  return 0;
}
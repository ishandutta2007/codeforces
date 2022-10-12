#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    vector<vector<pi>> mem(2);
    mem[s[0][1]-'0'].push_back({1,2});
    mem[s[1][0]-'0'].push_back({2,1});
    mem[1-(s[n-2][n-1]-'0')].push_back({n-1,n});
    mem[1-(s[n-1][n-2]-'0')].push_back({n,n-1});
    if(mem[0].size()>mem[1].size()){
      swap(mem[0],mem[1]);
    }
    cout << mem[0].size() << '\n';
    for(auto &nx : mem[0]){
      cout << nx.first << ' ';
      cout << nx.second << '\n';
    }
  }
  return 0;
}
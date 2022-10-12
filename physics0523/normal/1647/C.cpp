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
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    if(s[0][0]=='1'){cout << "-1\n";continue;}
    vector<pair<pi,pi>> res;
    for(int j=m-1;j>=1;j--){
      for(int i=0;i<n;i++){
        if(s[i][j]=='1'){
          res.push_back({{i,j-1},{i,j}});
        }
      }
    }
    for(int i=n-1;i>=1;i--){
      if(s[i][0]=='1'){
        res.push_back({{i-1,0},{i,0}});
      }
    }
    cout << res.size() << '\n';
    for(auto &nx : res){
      cout << nx.first.first+1 << ' ' << nx.first.second+1 << ' ';
      cout << nx.second.first+1 << ' ' << nx.second.second+1 << '\n';
    }
  }
  return 0;
}
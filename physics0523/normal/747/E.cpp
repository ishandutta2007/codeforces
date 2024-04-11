#include<bits/stdc++.h>

using namespace std;

queue<string> q;
vector<vector<string>> res;
void solve(int h){
  while(res.size()<h){res.push_back({});}
  string od=q.front();q.pop();
  res[h-1].push_back(od);
  od=q.front();q.pop();
  int cnt=stoi(od);
  for(int i=0;i<cnt;i++){
    solve(h+1);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  s.push_back(',');
  string cur;
  for(auto &nx : s){
    if(nx==','){
      q.push(cur);
      cur.clear();
    }
    else{cur.push_back(nx);}
  }
  while(!q.empty()){solve(1);}
  cout << res.size() << '\n';
  for(auto &nx : res){
    for(int i=0;i<nx.size();i++){
      if(i){cout << ' ';}
      cout << nx[i];
    }cout << '\n';
  }
  return 0;
}
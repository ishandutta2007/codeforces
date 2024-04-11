#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using ppi=pair<pi,int>;

vector<string> ans_str={"Carrots","Kiwis","Grapes","Waste"};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k,t;
  cin >> n >> m >> k >> t;
  set<pi> was;
  vector<ppi> ev;
  for(int i=0;i<k;i++){
    int x,y;
    cin >> x >> y;
    x--;y--;
    was.insert({x,y});
    ev.push_back({{x,y},-1});
  }
  for(int i=0;i<t;i++){
    int x,y;
    cin >> x >> y;
    x--;y--;
    if(was.find({x,y})!=was.end()){continue;}
    ev.push_back({{x,y},i});
  }
  vector<int> res(t,3);
  sort(ev.begin(),ev.end());
  int cwas=0;
  for(auto &nx : ev){
    if(nx.second==-1){cwas++;continue;}
    res[nx.second]=(nx.first.first*m+nx.first.second-cwas)%3;
  }

  for(auto &nx : res){
    cout << ans_str[nx] << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

vector<vector<int>> mem;
vector<vector<vector<int>>> lis;
set<int> dlist;
vector<int> cp;

bool rep(int tg){
  if(cp.empty()){return false;}
  int tl=cp.back();cp.pop_back();
  int id=mem[tl][tg];
  for(int i=0;;i++){
    if(lis[tl][id][i]==tg){
      dlist.insert(tg);
      return true;
    }
    if(dlist.find(lis[tl][id][i])!=dlist.end()){continue;}
    if(!rep(lis[tl][id][i])){return false;}
  }
  return false; //err
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k,n;
  cin >> k >> n;
  vector<pl> tp(k),mp(n);
  for(auto &nx : tp){cin >> nx.first >> nx.second;}
  for(auto &nx : mp){cin >> nx.first >> nx.second;}

  mem.resize(k);
  for(int i=0;i<k;i++){mem[i].resize(n);}
  lis.resize(k);

  for(int i=0;i<k;i++){
    map<pl,vector<pl>> dmp;
    for(int j=0;j<n;j++){
      long long dx=mp[j].first-tp[i].first;
      long long dy=mp[j].second-tp[i].second;
      long long g=gcd(dx,dy);
      dmp[{dx/g,dy/g}].push_back({abs(dx)+abs(dy),j});
    }
    for(auto &nx : dmp){
      sort(nx.second.begin(),nx.second.end());
      vector<int> clis;
      for(auto &ny : nx.second){
        mem[i][ny.second]=lis[i].size();
        clis.push_back(ny.second);
      }
      lis[i].push_back(clis);
    }
  }

  int res=0;
  for(int i=0;i<n;i++){
    vector<int> p;
    for(int j=0;j<k;j++){p.push_back(j);}
    bool isok=false;
    do{
      cp=p;
      dlist.clear();
      if(rep(i)){isok=true;break;}
    }while(next_permutation(p.begin(),p.end()));
    if(isok){res++;}
  }
  cout << res << '\n';
  return 0;
}
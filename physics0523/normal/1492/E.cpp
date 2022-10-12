#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> a;

vector<int> check(vector<int> &cand){
  for(int i=0;i<n;i++){
    int ec=0;
    for(int j=0;j<m;j++){
      if(a[i][j]!=cand[j]){ec++;}
    }
    if(ec>=3){
      vector<int> res;
      res.push_back(i);
      for(int j=0;j<m;j++){
        if(a[i][j]!=cand[j]){res.push_back(j);}
      }
      return res;
    }
  }
  return {};
}

bool found=false;
void work(vector<int> &cand,int step){
  if(found){return;}
  vector<int> ck=check(cand);
  if(ck.empty()){
    cout << "Yes\n";
    for(int i=0;i<cand.size();i++){
      if(i){cout << ' ';}
      cout << cand[i];
    }cout << '\n';
    found=true;
    return;
  }
  if(step>=4){return;}
  int tg=ck[0];
  int sz=ck.size()-1;
  if(sz>=5){return;}
  for(int i=1;i<=sz;i++){
    int mem=cand[ck[i]];
    cand[ck[i]]=a[tg][ck[i]];
    work(cand,step+1);
    cand[ck[i]]=mem;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  a.resize(n);
  for(auto &nx : a){
    nx.resize(m);
    for(auto &ny : nx){cin >> ny;}
  }

  vector<int> maj;
  for(int j=0;j<m;j++){
    map<int,int> mp;
    for(int i=0;i<n;i++){
      mp[a[i][j]]++;
    }
    int v=a[0][j];
    for(auto &nx : mp){
      if(mp[v]<nx.second){v=nx.first;}
    }
    maj.push_back(v);
  }
  work(maj,0);
  if(!found){cout << "No\n";}
  return 0;
}
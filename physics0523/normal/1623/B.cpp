#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

typedef struct{
  int l,r,d;
}dat;

vector<dat> res;
void rep(int l,int r,set<pi> &seg){
  //cerr << l << ' ' << r << '\n';
  if(seg.empty()){return;}
  if(l==r){
    res.push_back({l,r,l});
    return;
  }
  int cd;
  for(int i=l;i<=r;i++){
    if(i!=l && seg.find({l,i-1})==seg.end()){continue;}
    if(i!=r && seg.find({i+1,r})==seg.end()){continue;}
    cd=i;
  }
  set<pi> ls,rs;
  for(auto &nx : seg){
    if(nx.first==l && nx.second==r){continue;}
    if(nx.second<cd){ls.insert(nx);}
    else{rs.insert(nx);}
  }
  res.push_back({l,r,cd});
  rep(l,cd-1,ls);
  rep(cd+1,r,rs);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    res.clear();
    int n;
    cin >> n;
    set<pi> seg;
    for(int i=0;i<n;i++){
      pi v;
      cin >> v.first >> v.second;
      seg.insert(v);
    }
    rep(1,n,seg);
    for(auto &nx : res){
      cout << nx.l << ' ' << nx.r << ' ' << nx.d << '\n';
    }
  }
  return 0;
}
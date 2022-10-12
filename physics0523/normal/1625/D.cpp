#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

void merge(vector<pi> &a,vector<pi> &b){
  if(a.size()<b.size()){swap(a,b);}
  for(auto &nx : b){a.push_back(nx);}
  b.clear();
}

vector<pi> largest_xor_pair(vector<pi> &list,int tg){
  vector<pi> tr;
  tr.push_back({-1,-1});
  vector<pi> res;
  bool isfirst=true;
  for(auto &nx : list){
    int v=0;
    if(!isfirst){
      for(int i=tg;i>=0;i--){
        if(nx.first&(1<<i)){
          if(tr[v].second!=-1){v=tr[v].second;}
          else{v=tr[v].first;}
        }
        else{
          if(tr[v].first!=-1){v=tr[v].first;}
          else{v=tr[v].second;}
        }
      }
      if(res.empty() || (res[0].first^res[1].first)<(tr[v].first^nx.first)){
        res={tr[v],nx};
      }
    }

    isfirst=false;
    v=0;
    for(int i=tg;i>=0;i--){
      if(nx.first&(1<<i)){
        if(tr[v].first==-1){
          tr[v].first=tr.size();
          tr.push_back({-1,-1});
        }
        v=tr[v].first;
      }
      else{
        if(tr[v].second==-1){
          tr[v].second=tr.size();
          tr.push_back({-1,-1});
        }
        v=tr[v].second;
      }
    }
    tr[v]=nx;
  }
  return res;
}

int k;
vector<pi> solve(vector<pi> &list,int tg){
  if(list.size()<=1){return list;}
  if(tg==-1){return {list[0]};}

  if(k&(1<<tg)){
    vector<pi> res=largest_xor_pair(list,tg);
    if((res[0].first^res[1].first)>=k){return res;}
    return {res[0]};
  }
  else{
    vector<pi> a,b;
    for(auto &nx : list){
      if(nx.first&(1<<tg)){a.push_back(nx);}
      else{b.push_back(nx);}
    }
    vector<pi> sa=solve(a,tg-1);
    vector<pi> sb=solve(b,tg-1);
    merge(sa,sb);
    return sa;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n >> k;

  vector<pi> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i].first;
    a[i].second=i+1;
  }

  if(k==0){
    cout << n << '\n';
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << i+1;
    }cout << '\n';
    return 0;
  }

  vector<pi> res=solve(a,29);
  if(res.size()<=1){cout << "-1\n";return 0;}
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i].second;
  }cout << '\n';
  return 0;
}
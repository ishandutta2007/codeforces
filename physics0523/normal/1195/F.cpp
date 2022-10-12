// Range Kind Query
// usage: https://atcoder.jp/contests/abc174/submissions/34324350
#include<bits/stdc++.h>

using namespace std;

// Range Kind Query
// 0-indexed
template <typename T>
struct RangeKindQuery{
  int n,m;
  vector<int> comp;
  RangeKindQuery(const vector<T> &a){
    n=a.size();
    vector<pair<T,int>> pv;
    for(int i=0;i<n;i++){
      pv.push_back({a[i],i});
    }
    sort(pv.begin(),pv.end());

    int id=0;
    comp.resize(n);
    for(int i=0;i<n;i++){
      comp[pv[i].second]=id;
      if(i==n-1){break;}
      if(pv[i].first!=pv[i+1].first){id++;}
    }
    m=(id+1);
  }

  vector<int> work(const vector<pair<int,int>> &qv){
    int qs=qv.size();
    vector<int> res(qs);
    vector<vector<pair<int,int>>> qr(n);
    for(int i=0;i<qs;i++){
      qr[qv[i].second].push_back({qv[i].first,i});
    }

    int whole=0;
    vector<int> prev(m,-1);
    vector<int> bit(n+1,0);
    for(int i=0;i<n;i++){
      if(prev[comp[i]]!=-1){
        // add(prev[comp[i]]+1,-1)
        for(int idx=(prev[comp[i]]+1);idx<n;idx += (idx & -idx)){
          bit[idx]--;
        }
      }
      else{whole++;}

      prev[comp[i]]=i;
      // add(i+1,1)
      for(int idx=(i+1);idx<n;idx += (idx & -idx)){
        bit[idx]++;
      }

      for(auto &nx : qr[i]){
        int del=0;
        // sum(nx.first)
        for(int idx=nx.first;idx>0;idx -= (idx & -idx)){
          del+=bit[idx];
        }
        res[nx.second]=whole-del;
      }
    }
    return res;
  }
};

unsigned long long id(int l,int r){
  int g=gcd(abs(l),abs(r));
  l/=g;r/=g;
  unsigned long long res=(((unsigned long long)l)<<32)+r;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<unsigned long long> v;
  vector<int> sz={0};
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    vector<pair<int,int>> pv(m);
    for(auto &nx : pv){
      cin >> nx.first >> nx.second;
    }
    for(int j=0;j<m;j++){
      int dx=pv[(j+1)%m].first-pv[j].first;
      int dy=pv[(j+1)%m].second-pv[j].second;
      v.push_back(id(dx,dy));
    }
    sz.push_back(sz.back()+m);
  }

  int q;
  cin >> q;
  vector<pair<int,int>> ask;
  for(int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    ask.push_back({sz[l-1],sz[r]-1});
  }
  RangeKindQuery<unsigned long long> rkq(v);
  vector<int> res=rkq.work(ask);
  for(auto &nx : res){
    cout << nx << "\n";
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int search(int x,vector<int> &a,int n){
  int st=0,fi=n-1,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(a[te]<x){st=te+1;}else{fi=te-1;}
  }
  return st;
}

int solve(vector<int> &a,vector<int> &b){
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int n=a.size(),m=b.size();
  if(n==0 || m==0){return 0;}

  unordered_map<int,int> mp;
  for(auto &nx : a){mp[nx]++;}
  for(auto &nx : b){mp[nx]++;}
  vector<int> v;
  for(auto &nx : mp){
    if(nx.second==2){v.push_back(nx.first);}
  }
  int vs=v.size();
  sort(v.begin(),v.end());

  int res=0;
  for(int i=0;i<m;i++){
    if(b[i]<a[0]){continue;}
    int st=0,fi=n-1,te;
    while(st<=fi){
      te=(st+fi)/2;
      if(a[te]<=b[i]+te){st=te+1;}
      else{fi=te-1;}
    }
    int segs=b[i],segf=b[i]+fi;
    int cr=0;
    cr=search(segf+1,b,m)-search(segs,b,m);
    cr+=vs-search(segf+1,v,vs);
    res=max(cr,res);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> ma,pa;
    vector<int> mb,pb;

    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v<0){ma.push_back(-v);}
      else{pa.push_back(v);}
    }

    for(int i=0;i<m;i++){
      int v;
      cin >> v;
      if(v<0){mb.push_back(-v);}
      else{pb.push_back(v);}
    }

    cout << solve(ma,mb) + solve(pa,pb) << '\n';
  }
  return 0;
}
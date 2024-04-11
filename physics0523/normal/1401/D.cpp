#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using Graph=vector<vector<int>>;

long long n;
vector<long long> arr;
long long rep(int v,int pv,Graph &g){
  long long up=1;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    long long st=rep(nx,v,g);
    arr.push_back(st*(n-st));
    up+=st;
  }
  return up;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long m;
    cin >> m;
    vector<long long> p(m);
    for(auto &nx : p){cin >> nx;}
    sort(p.begin(),p.end());
    arr.clear();
    rep(0,-1,g);
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    long long tg=min(m-1,n-2);
    long long res=0;
    for(int i=0;i<m;i++){
      //cerr << i << ' ' << tg << '\n';
      arr[tg]%=mod;
      arr[tg]*=p[i];
      arr[tg]%=mod;
      tg--;
      tg=max(0ll,tg);
    }
    for(auto &nx : arr){
      nx%=mod;res+=nx;res%=mod;
    }
    cout << res << '\n';
  }
  return 0;
}
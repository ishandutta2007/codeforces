#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<int> a;
int k,res;
vector<int> rep(int v,int p,Graph &g){
  vector<int> r(k+1,0);
  vector<int> nr,ch;
  for(auto &e : g[v]){
    if(e==p){continue;}
    ch=rep(e,v,g);
    ch[k]=max(ch[k],ch[k-1]);
    for(int i=k-1;i>=1;i--){ch[i]=ch[i-1];}
    nr=r;
    for(int i=1;i<=k;i++){
      for(int j=1;j<=k;j++){
        if((i+j)<k){continue;}
        nr[min(i,j)]=max(r[i]+ch[j],nr[min(i,j)]);
      }
    }
    r.swap(nr);
  }
  r[0]=r[k]+a[v];
  for(int i=0;i<=k;i++){res=max(r[i],res);}
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n >> k;
  a.resize(n);k++;
  for(int i=0;i<n;i++){cin >> a[i];}
  if(n==1){cout << a[0] << '\n'; return 0;}
  Graph g(n);
  for(int i=0;i<(n-1);i++){
    int p,q;
    cin >> p >> q;
    p--;q--;
    g[p].push_back(q);
    g[q].push_back(p);
  }
  res=0;
  rep(1,-1,g);
  cout << res << '\n';
  return 0;
}
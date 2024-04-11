#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

pi ask(vector<int> &arr){
  if(arr.empty()){
    return {-1,-1};
  }
  cout << "? ";
  cout << arr.size();
  for(auto &nx : arr){
    cout << ' ' << nx;
  }cout << '\n';
  fflush(stdout);
  int p,q;
  cin >> p >> q;
  return {p,q};
}

void ans(int p,int q){
  cout << "! " << p << ' ' << q << '\n';
  fflush(stdout);
  string s;
  cin >> s;
  return;
}

vector<int> calcdist(int v,Graph &g,int n){
  vector<int> d(n+1,1e9);
  queue<int> q;
  d[v]=0;
  q.push(v);
  while(!q.empty()){
    int od=q.front();q.pop();
    for(auto &nx : g[od]){
      if(d[nx]>5e8){
        d[nx]=d[od]+1;
        q.push(nx);
      }
    }
  }
  return d;
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    Graph g(n+1);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> fa;
    for(int i=1;i<=n;i++){fa.push_back(i);}
    pi fv=ask(fa);
    int rt=fv.first;
    int d=fv.second;
    vector<int> mem=calcdist(rt,g,n);
    vector<vector<int>> dbk(n+1);
    for(int i=1;i<=n;i++){dbk[mem[i]].push_back(i);}
    int st=(d+1)/2,fi=d;
    int p;
    while(st<=fi){
      //cerr << "[" << st << ',' << fi << "]\n";
      int te=(st+fi+1)/2;
      vector<int> cq;
      for(int i=te;i<=d;i++){
        for(auto &nx : dbk[i]){cq.push_back(nx);}
      }
      pi sv=ask(cq);
      if(sv.second==d){
        p=sv.first;
        st=te+1;
      }
      else{fi=te-1;}
    }
    mem=calcdist(p,g,n);
    vector<int> lq;
    for(int i=1;i<=n;i++){
      if(mem[i]==d){lq.push_back(i);}
    }
    int q=ask(lq).first;
    ans(p,q);
  }
  return 0;
}
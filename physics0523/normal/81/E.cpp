#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

pi sump(pi a,pi b){return make_pair(a.first+b.first,a.second+b.second);}
pi subp(pi a,pi b){return make_pair(a.first-b.first,a.second-b.second);}

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

Graph DeComp(int n,Graph &g){
  Graph res,mem(n+1);
  UnionFind uf(n+1);
  for(int i=1;i<=n;i++){
    for(auto &nx : g[i]){uf.unionSet(i,nx);}
  }
  for(int i=1;i<=n;i++){mem[uf.root(i)].push_back(i);}
  for(int i=1;i<=n;i++){
    if(mem[i].size()!=0){res.push_back(mem[i]);}
  }
  return res;
}

void dfs(int v,int pv,vector<int> &arr,vector<int> &ord,Graph &g){
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    dfs(nx,v,arr,ord,g);
  }
  ord[v]=arr.size();
  arr.push_back(v);
}

pi treeDP(int n,vector<int> &s,Graph &g,vector<pi> &ra){
  vector<pi> dp(2*n,make_pair(0,0));
  vector<int> rest(n);
  vector<int> d(n);
  vector<int> arr,ord(n);
  vector<bool> fl(n,false);
  dfs(0,-1,arr,ord,g);
  int od;
  for(int i=0;i<n;i++){
    od=arr[i];
    rest[od]=od;
    for(auto &nx : g[od]){
      if(fl[nx]){dp[2*od]=sump(dp[2*od],dp[2*nx+1]);}
    }
    for(auto &nx : g[od]){
      if(fl[nx]){
        //cout << nx << "->" << od << '\n';
        pi cv=sump(subp(dp[2*od],dp[2*nx+1]),dp[2*nx]);
        pi dlt;
        if(s[nx]!=s[od]){dlt=make_pair(1,1);}
        else{dlt=make_pair(1,0);}
        cv=sump(cv,dlt);
        if(dp[2*od+1]<cv){
          dp[2*od+1]=cv;
          rest[od]=nx;
        }
      }
    }
    if(dp[2*od+1]<dp[2*od]){
      dp[2*od+1]=dp[2*od];
      rest[od]=od;
    }
    fl[od]=true;
    //cout << od << ':';
    //cout << dp[2*od].first << ' ' << dp[2*od].second << ',';
    //cout << dp[2*od+1].first << ' ' << dp[2*od+1].second << '\n';
  }
  for(int i=n-1;i>=0;i--){
    int v=arr[i];
    if(v!=rest[v] && fl[v] && fl[rest[v]]){
      fl[v]=false;
      fl[rest[v]]=false;
      ra.push_back(make_pair(v,rest[v]));
    }
  }
  return dp[2*od+1];
}

vector<int> s;
vector<bool> cir;
vector<int> d;
pi solve(vector<int> &subs,Graph &g,vector<pi> &ra){
  queue<int> q;
  vector<pi> el;
  for(auto &i : subs){
    for(auto &j : g[i]){if(i<j){el.push_back(make_pair(i,j));}}
    d[i]=g[i].size();cir[i]=true;
    if(d[i]==1){cir[i]=false;q.push(i);}
  }

  while(!q.empty()){
    int od=q.front();
    q.pop();
    for(auto &nx : g[od]){
      if(cir[nx]){
        d[nx]--;
        if(d[nx]==1){cir[nx]=false;q.push(nx);}
      }
    }
  }
  int id1=-1,id2=-1;
  int es=el.size();
  sort(el.begin(),el.end());
  for(int i=0;i<es;i++){
    if(cir[el[i].first] && cir[el[i].second]){
      if(id1==-1){id1=i;}
      else if(id2==-1){id2=i;}
    }
  }
  //cout << id1 << ' ' << id2 << '\n';

  int ss=subs.size();
  unordered_map<int,int> mp;
  vector<int> cs;
  for(int i=0;i<ss;i++){
    mp[subs[i]]=i;
    //cout << subs[i] << "->" << i << '\n';
    cs.push_back(s[subs[i]]);
  }

  Graph g1(ss);
  for(int i=0;i<es;i++){
    if(i==id1){continue;}
    int u=mp[el[i].first];
    int v=mp[el[i].second];
    g1[u].push_back(v);
    g1[v].push_back(u);
  }

  pi res1;
  vector<pi> ra1;
  res1=treeDP(ss,cs,g1,ra1);
  for(auto &nx : ra1){
    nx.first=subs[nx.first];
    nx.second=subs[nx.second];
  }

  Graph g2(ss);
  for(int i=0;i<es;i++){
    if(i==id2){continue;}
    int u=mp[el[i].first];
    int v=mp[el[i].second];
    g2[u].push_back(v);
    g2[v].push_back(u);
  }

  pi res2;
  vector<pi> ra2;
  res2=treeDP(ss,cs,g2,ra2);
  for(auto &nx : ra2){
    nx.first=subs[nx.first];
    nx.second=subs[nx.second];
  }

  if(res1>res2){
    ra=ra1;
    return res1;
  }
  else{
    ra=ra2;
    return res2;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cir.resize(n+1);
  s.resize(n+1);
  d.resize(n+1);
  Graph g(n+1);

  for(int i=1;i<=n;i++){
    int j;
    cin >> j >> s[i];
    g[i].push_back(j);
    g[j].push_back(i);
  }
  Graph dc=DeComp(n,g);

  pi res=make_pair(0,0);
  vector<pi> rp;
  for(auto &nx : dc){
    vector<pi> crp;
    res=sump(res,solve(nx,g,crp));
    rp.insert(rp.end(),crp.begin(),crp.end());
  }
  cout << res.first << ' ' << res.second << '\n';
  for(auto &nx : rp){cout << nx.first << ' ' << nx.second << '\n';}
  return 0;
}
#include<bits/stdc++.h>

using namespace std;
using p_q=priority_queue<int>;
using Graph=vector<vector<int>>;

void merge(p_q &a,p_q &b){
  if(a.size()<b.size()){swap(a,b);}
  while(!b.empty()){
    a.push(b.top());
    b.pop();
  }
}

p_q rep(int v,int pv,Graph &g){
  p_q cur;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    p_q ch=rep(nx,v,g);
    merge(cur,ch);
  }
  if(cur.empty()){cur.push(0);}
  int bn=cur.top();cur.pop();
  cur.push(bn+1);
  return cur;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  Graph g(n);
  for(int i=0;i<(n-1);i++){
    int p,q;
    cin >> p >> q;
    p--;q--;
    g[p].push_back(q);
    g[q].push_back(p);
  }
  p_q pq=rep(0,-1,g);
  long long rn=0,wn=0;
  long long res;
  if(pq.size()>=k){
    for(int i=0;i<k;i++){
      rn++;
      wn+=(pq.top()-1);
      pq.pop();
    }
    long long fn=n-rn-wn;
    res=1e18;
    for(long long bn=0;bn<=fn;bn++){
      long long cw=wn+(fn-bn);
      res=min(res,cw*(rn-bn));
    }
  }
  else{
    res=0;
    for(long long i=pq.size();i<=k;i++){
      res=max(res,i*(n-i));
    }
  }
  cout << res << '\n';
  return 0;
}
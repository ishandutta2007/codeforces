// based on :
// https://atcoder.jp/contests/dp/submissions/10516174

// Li Chao Segment Tree - trial
// dp(@)-Z
#include<bits/stdc++.h>

using namespace std;

#define llinf 4154118101919364364

long long llmin(long long a,long long b){if(a<b){return a;}return b;}

//f(x) = (x-vertex)^2 + cv
typedef struct{
  long long vertex;
  long long cv;
}func;

long long fcalc(long long x,func f){
  return (x-f.vertex)*(x-f.vertex)+f.cv;
}

func li_chao[262144];
long long stree_size=131072;

void sinit(){
  long long i;
  for(i=0;i<262144;i++){
    li_chao[i].vertex=0;
    li_chao[i].cv=llinf;
  }
}

//add func f
//call:k=0,st=0,fi=0
void add(func f,long long k,long long st,long long fi){
  long long nst=fcalc(st,f),nfi=fcalc(fi-1,f);
  long long pst=fcalc(st,li_chao[k]),pfi=fcalc(fi-1,li_chao[k]);
  if(nst>=pst && nfi>=pfi){return;}
  if(nst<=pst && nfi<=pfi){
    li_chao[k]=f;
    return;
  }
  long long mid=(st+fi)/2;
  add(f,2*k+1,st,mid);
  add(f,2*k+2,mid,fi);
}

//get min f(x)
long long get(long long x){
  long long p=x+stree_size-1,res=llinf;
  while(p>=0){
    res=llmin(fcalc(x,li_chao[p]),res);
    if(p==0){break;}
    p=(p-1)/2;
  }
  return res;
}

using pl=pair<long long,long long>;
using Graph=vector<vector<pl>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,k;
  cin >> n >> m >> k;
  Graph g(n+1);
  for(int i=0;i<m;i++){
    long long u,v,w;
    cin >> u >> v >> w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }
  vector<long long> dp(n+1,8e18);
  dp[1]=0;

  for(long long flight=0;flight<=k;flight++){
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    for(int i=1;i<=n;i++){
      if(dp[i]<6e18){
        pq.push({dp[i],i});
      }
    }

    while(!pq.empty()){
      pl od=pq.top();pq.pop();
      if(dp[od.second]<od.first){continue;}
      for(auto &nx : g[od.second]){
        long long nv=nx.first;
        long long nd=dp[od.second]+nx.second;
        if(dp[nv]>nd){
          dp[nv]=nd;
          pq.push({nd,nv});
        }
      }
    }
    if(flight==k){break;}
    sinit();
    for(int i=1;i<=n;i++){
      if(dp[i]<6e18){
        func f;
        f.vertex=i;
        f.cv=dp[i];
        add(f,0,0,stree_size);
      }
    }
    for(int i=1;i<=n;i++){
      dp[i]=get(i);
    }
  }

  for(int i=1;i<=n;i++){
    if(i-1){cout << " ";}
    cout << dp[i];
  }cout << "\n";
  return 0;
}
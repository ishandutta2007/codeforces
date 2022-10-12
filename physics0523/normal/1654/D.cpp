#include<bits/stdc++.h>
#define mod 998244353
#define MAX_NUM 300000

using namespace std;
using pi=pair<int,int>;
using pip=pair<int,pi>;
using Graph=vector<vector<pip>>;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

vector<vector<int>> pfac;
vector<long long> minv;

void rep(int v,int pv,vector<int> &cur,vector<int> &mih,Graph &g){
  for(auto &nx : g[v]){
    int tg=nx.first;
    int ad=nx.second.first;
    int rm=nx.second.second;
    if(pv==tg){continue;}

    for(auto &ny : pfac[ad]){cur[ny]++;}
    for(auto &ny : pfac[rm]){
      cur[ny]--;
      mih[ny]=min(mih[ny],cur[ny]);
    }
    rep(tg,v,cur,mih,g);
    for(auto &ny : pfac[rm]){cur[ny]++;}
    for(auto &ny : pfac[ad]){cur[ny]--;}
  }
}

long long res;
void sol(int v,int pv,long long val,Graph &g){
  res+=val;res%=mod;
  for(auto &nx : g[v]){
    int tg=nx.first;
    int ad=nx.second.first;
    int rm=nx.second.second;
    if(pv==tg){continue;}

    long long nval=val;
    for(auto &ny : pfac[ad]){nval*=ny;nval%=mod;}
    for(auto &ny : pfac[rm]){nval*=minv[ny];nval%=mod;}
    sol(tg,v,nval,g);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  pfac.resize(MAX_NUM);
  for(int i=2;i<MAX_NUM;i++){
    if(!pfac[i].empty()){continue;}
    for(int j=i;j<MAX_NUM;j+=i){
      int cj=j;
      while(cj%i==0){
        pfac[j].push_back(i);
        cj/=i;
      }
    }
  }
  minv.resize(MAX_NUM);
  for(int i=1;i<MAX_NUM;i++){minv[i]=modular_inverse(i);}

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v,x,y;
      cin >> u >> v >> x >> y;
      u--;v--;
      int gc=gcd(x,y);
      x/=gc;y/=gc;
      g[u].push_back({v,{y,x}});
      g[v].push_back({u,{x,y}});
    }

    vector<int> cur(n+1,0),mih(n+1,0);
    rep(0,-1,cur,mih,g);
    long long fir=1;
    for(int i=2;i<=n;i++){
      fir*=power(i,(-mih[i]));
      fir%=mod;
    }
    res=0;
    sol(0,-1,fir,g);
    cout << res << '\n';
  }
  return 0;
}
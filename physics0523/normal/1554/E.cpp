#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
using Graph=vector<vector<int>>;

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

int param;
bool flag;
int judge(int v,int bk,Graph &g){
  if(!flag){return -1;}
  int sig=0;
  for(auto &nx : g[v]){
    if(nx==bk){continue;}
    sig+=judge(nx,v,g);
  }
  //cout << v << ',' << sig << '\n';
  if(sig%param==0){return 1;}
  if((sig+1)%param==0){return 0;}
  flag=false;
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    Graph g(n+1);
    for(int i=1;i<n;i++){
      int a,b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> f(n+1,0);
    for(int i=n-1;i>=1;i--){
      if((n-1)%i){continue;}
      param=i;flag=true;

      int cv;
      if(i==1){f[i]=power(2,n-1);}
      else{
        judge(1,-1,g);
        if(flag){f[i]=1;}
      }
      for(int j=2*i;j<=n;j+=i){
        f[i]+=mod;
        f[i]-=f[j];
        f[i]%=mod;
      }
    }
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << f[i];
    }cout << '\n';
  }
  return 0;
}
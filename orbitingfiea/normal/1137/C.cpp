#include<bits/stdc++.h>
#define ll long long
using namespace std;


int n, m, mod;
vector<int>G[101000];

stack<int>st;
int dfn[101000], low[101000], dft, bel[101000], cnb;
vector<int>blo[101000];
int f[101000][55], g[101000][55];

ll vis[101000], opn[101000];

ll ful(int b){
  return (1ll<<b)-1;
}
ll hou(ll x,int b){
/*
  ll y=0;
  for (register int i=0;i<mod;++i)
    if (x>>i&1)
      y|=1ll<<(i+b)%mod;
  return y;
  */
  return (x&ful(mod-b))<<b|(x>>(mod-b));
}
ll qian(ll x,int b){
  return hou(x,(mod-b)%mod);
}

void gid(int id[55],int x){
  for (int i=0;i<mod;++i){
    int sum=0;
    for (int p=(i+1)%mod;;p=(p+1)%mod){
      if (vis[x]>>p&1) break;
      ++sum;
    }
    id[i]=sum;
  }
}

bitset<101000>fucked;
void fuck(int b){
  if (fucked[b]) return;
  fucked[b]=1;
  
  memcpy(g[b],f[b],sizeof f[b]);
  for (auto x:blo[b])
    for (auto y:G[x])
      if (bel[x]!=bel[y]){
        fuck(bel[y]);
        static int id[55];
        gid(id,y);
        for (int i=0;i<mod;++i){
          ll st=qian(vis[x],i);
          for (int j=0;j<mod;++j)
            if (st>>j&1)
              g[b][i]=max(g[b][i],f[b][i]+g[bel[y]][id[j]]);
        }
      }
}

void gao(int b){
  queue<int>q; int s=blo[b].back();
  vis[s]|=1<<0; q.push(s);
  for (;!q.empty();){
    int x=q.front(); q.pop();
    ll t=hou(vis[x],1);
    for (auto y:G[x])
      if (bel[y]==bel[x])
        if ((t&vis[y])!=t){
          vis[y]|=t;
          q.push(y);
        }
  }
  for (int i=0;i<mod;++i){
    for (auto x:blo[b])
      if (opn[x]&qian(vis[x],i)){
        f[b][i]++;
      }
  }
}

void tar(int x){
  dfn[x]=low[x]=++dft;
  st.push(x);
  for (auto y:G[x]){
    if (!dfn[y]){
      tar(y);
      low[x]=min(low[x],low[y]);
    }else{
      if (!bel[y])
        low[x]=min(low[x],dfn[y]);
    }
  }
  if (low[x]==dfn[x]){
    ++cnb;
    while (st.top()!=x){
      bel[st.top()]=cnb;
      blo[cnb].push_back(st.top());
      st.pop();
    }
    if (1){
      bel[st.top()]=cnb;
      blo[cnb].push_back(st.top());
      st.pop();
    }
  }
}

int main(){
  while (0){
    mod=50;
    ll x=rand()%ful(50), b=rand()%mod;
    ll y=hou(x,b);
    for (int i=0;i<mod;++i){
      int j=(i+b)%mod;
      if ((x>>i&1)!=(y>>j&1)){
   		 cout<<x<<' '<<b<<' '<<y<<endl;
      	
        assert(0);
        }
    }
    cout<<x<<' '<<b<<' '<<y<<endl;
  }
  
  cin>>n>>m>>mod;
  for (int i=1;i<=m;++i){
    int u, v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
  }
  for (int i=1;i<=n;++i){
    static char s[55];
    scanf("%s",s);
    for (int j=0;j<mod;++j)
      if (s[j]=='1')
        opn[i]|=1ll<<j;
  }
  tar(1);
  for (int i=1;i<=cnb;++i){
    gao(i);
  }
  fuck(cnb);
  printf("%d\n",g[cnb][0]);
}
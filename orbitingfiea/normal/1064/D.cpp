//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n, m, sx, sy, lim1, lim2, inf=1e7;
char s[2020][2020];
bool used[2020][2020];
int d[2020][2020];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

#define pii pair<int,int>
#define fi first
#define se second

deque<pii>q;

bool chk(int i,int j){
  if (s[i][j]=='*') return 0;
  int a=d[i][j], b=sy-j;
  int c=(a+b)/2, d=(a-b)/2;
  return (c<=lim1&&d<=lim2&&c>=0&&d>=0);
}

void Dj(){
  q.clear(); memset(d,62,sizeof d);
  d[sx][sy]=0; q.push_back((pii){sx,sy});
  for (;!q.empty();){
    pii u=q.front(); q.pop_front();
    if (used[u.fi][u.se]) continue;
    used[u.fi][u.se]=1;
    for (int k=0;k<4;++k){
      pii v=(pii){u.fi+dx[k],u.se+dy[k]};
      if (s[v.fi][v.se]!='.') continue;
      int z=d[u.fi][u.se]+(k<2);
      if (d[v.fi][v.se]>z){
        d[v.fi][v.se]=z;
        if (chk(v.fi,v.se)){
          if (k<2) q.push_back(v);
          else q.push_front(v);
        }
      }
    }
  }
}

int main(){
  cin>>n>>m>>sx>>sy>>lim1>>lim2;
  //lim1=min(lim1,inf); lim2=min(lim2,inf);
  for (int i=1;i<=n;++i) scanf("%s",s[i]+1);
  Dj();
  int ans=0;
  for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j)
      ans+=chk(i,j);
  cout<<ans<<endl;
}
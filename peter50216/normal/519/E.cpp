// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}
int n;
vector<int> ed[101000];
int pre[20][101000];
int hei[101000];

map<PII,int> ss;

inline int sub(int p,int x){
  int &d=ss[MP(x,p)];
  if(d!=0)return d;
  d=1;
  for(int y:ed[x]){
    if(y==p)continue;
    d+=sub(x,y);
  }
  return d;
}
inline int go(int y,int d){
  int c=0;
  while(d){
    if(d%2)y=pre[c][y];
    d/=2;
    c++;
  }
  return y;
}

inline int lca(int x,int y,PII& lp){
  // hei[x]<=hei[y]
  lp={-1,-1};
  int diff=hei[y]-hei[x];
  y=go(y,diff);
  if(x==y)return x;
  PER(i,20){
    if(pre[i][x]!=pre[i][y]){
      x=pre[i][x];
      y=pre[i][y];
    }
  }
  lp={x,y};
  return pre[0][x];
}

inline int solve(int x,int y){
  if(x==y)return n;
  if(hei[x]>hei[y])swap(x,y);
  if((hei[x]+hei[y])%2)return 0;
  PII lp;
  int o=lca(x,y,lp);
  int dis=hei[x]+hei[y]-hei[o]*2;
  // hei[x]<=hei[y]
  int mp=go(y,dis/2);
    int yy=go(y,dis/2-1);

  if(lp.first<0){    return n-sub(mp,yy)-sub(mp,pre[0][mp]);
  }else if(hei[x]==hei[y]){
    return n-sub(mp,lp.first)-sub(mp,yy);
  }else{
    return n-sub(mp,pre[0][mp])-sub(mp,yy);
  }
}

inline void dfs(int x,int p,int h){
  pre[0][x]=p;
  hei[x]=h;
  for(int y:ed[x]){
    if(y==p)continue;
    dfs(y,x,h+1);
  }
}

int main(){
  RI(n);
  REP(i,n-1){
    DRII(x,y);
    x--;y--;
    ed[x].push_back(y);
    ed[y].push_back(x);
  }
  dfs(0,-1,0);
  pre[0][0]=0;
  REP(i,19){
    REP(j,n){
      pre[i+1][j]=pre[i][pre[i][j]];
    }
  }
  DRI(q);
  while(q--){
    DRII(x,y);
    x--;y--;
    printf("%d\n",solve(x,y));
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
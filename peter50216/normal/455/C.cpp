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

vector<int> ed[301000];
bool vis[301000];

int pre[301000];
int ld[301000];
inline PII dfs(int np,int p,int b){
  pre[np]=b;
  vis[np]=1;
  int a1=1;
  int m1=0,m2=0;
  REP(i,SZ(ed[np])){
    int y=ed[np][i];
    if(y==p)continue;
    PII ret=dfs(y,np,b);
    a1=max(a1,ret.first);
    if(ret.second>m1){
      m2=m1;m1=ret.second;
    }else if(ret.second>m2){
      m2=ret.second;
    }
  }
  a1=max(a1,m1+m2+1);
  return make_pair(a1,m1+1);
}
inline int find(int x){
  return x==pre[x]?x:pre[x]=find(pre[x]);
}
inline int mm(int a,int b){
  int ret=max(a,b);
  int aa=(a+1)/2,bb=(b+1)/2;
  ret=max(ret,aa+bb+1);
  return ret;
}

int main(){
  DRIII(n,m,q);
  REP(i,m){
    DRII(a,b);a--;b--;
    ed[a].push_back(b);ed[b].push_back(a);
  }
  REP(i,n)if(!vis[i]){
    ld[i]=dfs(i,-1,i).first-1;
  }
  while(q--){
    DRI(t);
    if(t==1){
      DRI(x);x--;
      PI(ld[find(x)]);
    }else{
      DRII(x,y);x--;y--;
      x=find(x);y=find(y);
      if(x==y)continue;
      pre[x]=y;
      ld[y]=mm(ld[x],ld[y]);
    }
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
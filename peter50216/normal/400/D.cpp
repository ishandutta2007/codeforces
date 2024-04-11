// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
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

int ci[510];
int typ[101000];
int dis[510][510];
const int INF=1000000000;
int pre[101000];
inline int find(int a){
  return pre[a]==a?a:pre[a]=find(pre[a]);
}
int main(){
  DRIII(n,m,k);
  int t=0;
  REP(i,k){
    DRI(c);
    REP1(j,t,t+c-1)typ[j]=i;
    t+=c;
  }
  REP(i,n)pre[i]=i;
  REP(i,k)REP(j,k)dis[i][j]=(i==j)?0:INF;
  while(m--){
    DRIII(a,b,d);
    a--;b--;
      if(d==0){
        pre[find(a)]=find(b);
      }
    if(typ[a]!=typ[b]){
      a=typ[a];b=typ[b];
      dis[a][b]=dis[b][a]=min(dis[a][b],d);
    }
  }
  REP(i,n){
    if(i&&typ[i-1]==typ[i]&&find(i-1)!=find(i)){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  REP(kk,k)REP(i,k)REP(j,k){
    dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
  }
  REP(i,k)REP(j,k){
    printf("%d%c",dis[i][j]==INF?-1:dis[i][j],SEP(j==k-1));
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
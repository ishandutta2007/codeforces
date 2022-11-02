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
vector<int> ed[510];
int g[510][510];
int n,m;
vector<int> e2[510];
int cen;
inline int toi(int x){return x>cen?x-1:x;}
int vis[510],visid;
int pre[510];
inline bool run(int np){
  if(vis[np]==visid)return 0;
  vis[np]=visid;
  REP(j,SZ(e2[np])){
    int y=e2[np][j];
    if(pre[y]==-1||run(pre[y])){
      pre[y]=np;
      return 1;
    }
  }
  return 0;
}
inline int solve(){
  int cnt=0;
  REP(i,n)e2[i].clear();
  REP(i,n){
    if(i==cen)continue;
    int ii=toi(i);
    REP(j,SZ(ed[i])){
      int jj=ed[i][j];
      if(jj==cen)continue;
      cnt++;
      e2[ii].push_back(toi(jj));
    }
  }
  int mm=0;
  MS0(vis);visid=0;
  MS1(pre);
  REP(i,n-1){
    visid++;
    if(run(i))mm++;
  }
  return cnt+(n-1)-2*mm;
}
int main(){
  RII(n,m);
  while(m--){
    DRII(a,b);
    a--;b--;
    ed[a].PB(b);
    g[a][b]=1;
  }
  int ans=1000000000;
  REP(i,n){
    int c=0;
    if(!g[i][i])c++;
    REP(j,n){
      if(j==i)continue;
      if(!g[i][j])c++;
      if(!g[j][i])c++;
    }
    cen=i;
    c+=solve();
    ans=min(ans,c);
  }
  printf("%d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
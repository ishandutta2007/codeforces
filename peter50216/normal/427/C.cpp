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

vector<int> ed[101000];
vector<int> de[101000];
int co[101000];
int idx[101000],ii;
bool vis[101000];
inline void dfs(int np){
  if(vis[np])return;
  vis[np]=1;
  REP(i,SZ(ed[np])){
    dfs(ed[np][i]);
  }
  idx[ii++]=np;
}
vector<int> cc;
inline void rdfs(int np){
  if(vis[np])return;
  vis[np]=1;
  cc.push_back(np);
  REP(i,SZ(de[np])){
    rdfs(de[np][i]);
  }
}
int main(){
  DRI(n);
  REP(i,n)RI(co[i]);
  DRI(m);
  while(m--){
    DRII(a,b);
    a--;b--;
    ed[a].push_back(b);
    de[b].push_back(a);
  }
  MS0(vis);
  ii=0;
  REP(i,n){
    if(!vis[i])dfs(i);
  }
  MS0(vis);
  LL ans=0,wa=1;
  int mod=1000000007;
  PER(i,n){
    int np=idx[i];
    if(!vis[np]){
      cc.clear();
      rdfs(np);
      int mi=1000000010,mc=0;
      REP(j,SZ(cc)){
        int c=co[cc[j]];
        if(c<mi){
          mi=c;mc=1;
        }else if(c==mi){
          mc++;
        }
      }
      ans+=mi;
      wa=(wa*(LL)mc)%mod;
    }
  }
  printf("%I64d %d\n",ans,(int)wa);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
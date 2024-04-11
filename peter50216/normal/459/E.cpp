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

struct XD{
  int x,y,v;
  bool operator<(const XD& b)const{
    return v<b.v;
  }
};
vector<XD> allv;

int dis[2][301000];
int main(){
  DRII(n,m);
  allv.reserve(m);
  REP(i,m){
    DRIII(a,b,v);
    a--;b--;
    allv.push_back(XD{a,b,v});
  }
  sort(allv.begin(),allv.end());
  int c1=0,c2=1;
  int i,j;
  for(i=0;i<m;i=j){
    vector<int> upd;
    for(j=i;j<m&&allv[i].v==allv[j].v;j++){
      // printf("Do %d -> %d = %d\n",allv[j].x,allv[j].y,allv[j].v);
      if(dis[c2][allv[j].y]<dis[c1][allv[j].x]+1){
        dis[c2][allv[j].y]=dis[c1][allv[j].x]+1;
        upd.push_back(allv[j].y);
      }
    }
    REP(k,SZ(upd))dis[c1][upd[k]]=dis[c2][upd[k]];
    // REP(k,n)printf("dis[%d]=%d %d\n",k,dis[c1][k],dis[c2][k]);
  }
  int ans=0;
  REP(i,n)ans=max(ans,dis[c2][i]);
  PI(ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
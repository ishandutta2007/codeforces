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

pair<int,int> que[101000];
map<pair<int,int>,int> dis;
int dx[8]={1,1,1,0,-1,-1,-1,0},dy[8]={1,0,-1,-1,-1,0,1,1};
int main(){
  DRII(x0,y0);
  DRII(x1,y1);
  DRI(n);
  set<pair<int,int>> pts;
  REP(i,n){
    DRIII(r,a,b);
    REP1(j,a,b)pts.insert(make_pair(r,j));
  }
  int qs=0,qe=0;
  que[qe++]=make_pair(x0,y0);
  while(qs<qe){
    auto r=que[qs++];
    int d=dis[r];
    int x=r.first,y=r.second;
    REP(k,8){
      int xx=x+dx[k],yy=y+dy[k];
      auto tt=make_pair(xx,yy);
      if(!pts.count(tt)||dis.count(tt))continue;
      dis[tt]=d+1;que[qe++]=tt;
    }
  }
  auto e=make_pair(x1,y1);
  printf("%d\n",dis.count(e)?dis[e]:-1);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
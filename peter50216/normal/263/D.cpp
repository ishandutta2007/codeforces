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
int ps[101000];
int pid[101000];
int main(){
  DRIII(n,m,k);
  REP(i,m){
    DRII(a,b);a--;b--;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  MS1(pid);
  ps[0]=0;
  pid[0]=0;
  int nl=1,np=0;
  while(1){
    int fy;
    REP(i,SZ(ed[np])){
      int y=ed[np][i];
      if(pid[y]==-1){
        fy=y;
        break;
      }else if(nl-pid[y]>k){
        printf("%d\n",nl-pid[y]);
        REP1(i,pid[y],nl-1)printf("%d%c",ps[i]+1,SEP(i==nl-1));
        return 0;
      }
    }
    pid[fy]=nl;ps[nl]=fy;nl++;
    np=fy;
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
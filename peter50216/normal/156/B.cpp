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

bool canb[101000];

int ai[101000];
int cc[101000];
int cnc[101000];

int main(){
  DRII(n,m);
  int cnct=0;
  REP1(i,1,n){
    RI(ai[i]);
    if(ai[i]<0){
      cnc[-ai[i]]++;
      cnct++;
    }else cc[ai[i]]++;
  }
  int cr=0;
  REP1(i,1,n){
    if(cc[i]+cnct-cnc[i]==m){
      canb[i]=1;
      cr++;
    }else canb[i]=0;
  }
  REP1(i,1,n){
    if(ai[i]>0){
      if(canb[ai[i]]==0)puts("Lie");
      else if(cr>1)puts("Not defined");
      else puts("Truth");
    }else{
      if(canb[-ai[i]]==0)puts("Truth");
      else if(cr>1)puts("Not defined");
      else puts("Lie");
    }
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
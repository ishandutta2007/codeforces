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

int x[10],y[10];
int solx[10],soly[10];
int n,r;
inline int calc(){
  int rr=0;
  REP(i,n)REP1(j,i+1,n-1){
    rr+=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  }
  return rr;
}
inline int calcone(int i){
  int rr=0;
  REP(j,n){
    rr+=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  }
  return rr;
}
int per[10];
const double PI=acos(-1);
int main(){
  RII(n,r);
  time_t st=clock();
  int ga=0;
  while(clock()-st<2.5*CLOCKS_PER_SEC){
    REP(i,n){
      int xx,yy;
      do{
        xx=rand()%(2*r+1)-r;
        yy=rand()%(2*r+1)-r;
      }while(xx*xx+yy*yy>r*r);
      x[i]=xx;
      y[i]=yy;
    }
    REP(i,n)per[i]=i;
    int ans=calc();
    while(1){
      int oa=ans;
      random_shuffle(per,per+n);
      REP(ii,n){
        int i=per[ii];
        int pa=calcone(i);
        for(int xx=-r;xx<=r;xx++)for(int yy=-r;yy<=r;yy++){
          if(xx*xx+yy*yy>r*r)continue;
          int ox=x[i],oy=y[i];
          x[i]=xx;y[i]=yy;
          int aa=calcone(i);
          if(aa>pa){
            ans+=aa-pa;
            pa=aa;
          }else{
            x[i]=ox;y[i]=oy;
          }
        }
      }
      if(ans==oa)break;
    }
    if(ga<ans){
      ga=ans;
      REP(i,n){
        solx[i]=x[i];
        soly[i]=y[i];
      }
    }
  }
  REP(i,n){
    x[i]=solx[i];y[i]=soly[i];
  }
  int ans=calc();
  printf("%d\n",ans);
  REP(i,n)printf("%d %d\n",x[i],y[i]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
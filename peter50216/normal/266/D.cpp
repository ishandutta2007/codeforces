// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y);
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z);
#define RS(x) scanf("%s",x);
#define PI(x) printf("%d\n",x);
#define PIS(x) printf("%d ",x);
#define CASET int ___T,cas=1;scanf("%d",&___T);while(___T--)
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
#else
#define FILEIO(x) ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

int dis[210][210];
int od[210][210];
PII as[210];
const int INF=1000000000;
int main(){
    DRII(n,m);
    REP(i,n)REP(j,n){
        dis[i][j]=(i==j)?0:INF;
        od[i][j]=(i==j)?0:INF;
    }
    REP(i,m){
        DRIII(a,b,l);
        a--;b--;
        dis[a][b]=dis[b][a]=l*2;
        od[a][b]=od[b][a]=l*2;
    }
    REP(k,n)REP(i,n)REP(j,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int ans=1000000000;
    REP(i,n)REP1(j,i+1,n-1){
        if(od[i][j]==INF)continue;
        int dd=od[i][j];
        //            printf("%d %d %lf %lf\n",i,j,l,r);
        int pc=0;
//        printf("i=%d j=%d\n",i,j);
        REP(x,n){
            int xx=(dis[j][x]-dis[i][x]+dd)/2;
            int yy=dis[i][x]+xx;
//            printf("%d %d\n",xx,yy);
            as[x]=MP(xx-yy,xx+yy);
//            printf("%d %d\n",as[x].F,as[x].S);
        }
        sort(as,as+n);
        int mt1=-1000000000,mt2=-1000000000;
        int my=-1000000000;
        REP(i,n){
            if(i>0&&as[i].S>my){
                int xx=as[i].F;
                int yy=my;
                ans=min(ans,(yy-xx)/2);
            }
            mt1=max(mt1,-as[i].F);
            mt2=max(mt2,as[i].S-dd);
            my=max(my,as[i].S);
        }
        ans=min(ans,mt1);
        ans=min(ans,mt2);
//        printf("ans=%d\n",ans);
    }
    printf("%.10lf\n",ans/2.0);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
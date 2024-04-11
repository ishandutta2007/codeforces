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
typedef pair<int,int> PII;
typedef long long LL;
// }}}

double p[101000];
double d[101000];
int main(){
    DRI(n);
    REP1(i,1,n)scanf("%lf",&p[i]);
    p[0]=0;
    p[n+1]=0;
    n++;
    d[0]=0;
    double s0=1,s1=0,s2=0,ds0=0;
    double ss0=0,ss1=0,ss2=0;
    REP1(i,1,n){
        d[i]=(ds0+s2-ss2)*(1-p[i]);
        s2=(s2+s0+2*s1)*p[i];
        s1=(s1+s0)*p[i];
        s0=s0*p[i]+1;
        ss2=(ss2+ss0+2*ss1)*p[i];
        ss1=(ss1+ss0)*p[i];
        ss0=(ss0+1)*p[i];
        ds0=ds0*p[i]+d[i];
    }
    printf("%.15lf\n",d[n]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
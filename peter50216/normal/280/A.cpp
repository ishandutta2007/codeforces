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

int main(){
    const double pi=acos(-1);
    double w,h,a;
    scanf("%lf%lf%lf",&w,&h,&a);
    if(fabs(a-90)<1e-6){
        printf("%.10lf\n",min(w,h)*min(w,h));
        return 0;
    }
    if(a>90)a=180-a;
    if(fabs(a)<1e-6){
        printf("%.10lf\n",w*h);
        return 0;
    }
    a=a/180*pi;
    if(w<h)swap(w,h);
    double ans=w*h;
    double p1x=-w/2*cos(a)-h/2*sin(a);
    double p1y=-w/2*sin(a)+h/2*cos(a);
    double p2x=w/2*cos(a)-h/2*sin(a);
    double p2y=w/2*sin(a)+h/2*cos(a);
    double p3x=-w/2*cos(a)+h/2*sin(a);
    double p3y=-w/2*sin(a)-h/2*cos(a);
    if(a<=atan2(h,w)*2){
        double xi1=((p2y-h/2)*p1x+(h/2-p1y)*p2x)/(p2y-p1y)+w/2;
        double yi1=h/2-((p2x-(-w/2))*p1y+((-w/2)-p1x)*p2y)/(p2x-p1x);
        double xi2=((p3y-(-h/2))*p1x+((-h/2)-p1y)*p3x)/(p3y-p1y)+w/2;
        double yi2=((p3x-(-w/2))*p1y+((-w/2)-p1x)*p3y)/(p3x-p1x)-(-h/2);
        //printf("%lf %lf %lf %lf\n",xi1,yi1,xi2,yi2);
        ans-=xi1*yi1+xi2*yi2;
    }else{
        double xi1=((p2y-h/2)*p1x+(h/2-p1y)*p2x)/(p2y-p1y)+w/2;
        double xi2=((p2y-(-h/2))*p1x+((-h/2)-p1y)*p2x)/(p2y-p1y)+w/2;
        ans-=h*(xi1+xi2);
    }
    printf("%.10lf\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
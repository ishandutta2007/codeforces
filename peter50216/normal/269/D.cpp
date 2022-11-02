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

struct XD{
    int h,x,y;
    int xi,yi;
    bool operator<(const XD& b)const{
        return h<b.h;
    }
}in[101000];
int dp[101000];
int xs[201000];
set<int> dc[101000];
int tre[1001000];
inline int que(int np,int l,int r,int x){
    if(l==r){
        return tre[np];
    }
    if(tre[np]!=-1){
        tre[np*2]=tre[np*2+1]=tre[np];
        tre[np]=-1;
    }
    int m=(l+r)/2;
    if(x<=m)return que(np*2,l,m,x);
    else return que(np*2+1,m+1,r,x);
}
inline int que(int np,int l,int r,int x,int y){
    if(l==x&&r==y){
        return tre[np];
    }
    if(tre[np]!=-1){
        tre[np*2]=tre[np*2+1]=tre[np];
    }
    int m=(l+r)/2;
    if(x<=m&&y>m){
        int x1=que(np*2,l,m,x,m);
        int x2=que(np*2+1,m+1,r,m+1,y);
        if(x1==x2)return x1;
        return -1;
    }else if(x>m){
        return que(np*2+1,m+1,r,x,y);
    }else{
        return que(np*2,l,m,x,y);
    }
}
inline void cov(int np,int l,int r,int x,int y,int c){
    if(l==x&&r==y){
        tre[np]=c;
        return;
    }
    if(tre[np]!=-1){
        tre[np*2]=tre[np*2+1]=tre[np];
        tre[np]=-1;
    }
    int m=(l+r)/2;
    if(x<=m&&y>m){
        cov(np*2,l,m,x,m,c);
        cov(np*2+1,m+1,r,m+1,y,c);
    }else if(x>m){
        cov(np*2+1,m+1,r,x,y,c);
    }else{
        cov(np*2,l,m,x,y,c);
    }
}
int main(){
    DRII(n,t);
    REP(i,n){
        RIII(in[i].h,in[i].x,in[i].y);
    }
    in[n].h=t;
    in[n].x=-1000000000;
    in[n].y=1000000000;
    n++;
    in[n].h=0;
    in[n].x=-1000000000;
    in[n].y=1000000000;
    n++;
    sort(in,in+n);
    int xc=0;
    REP(i,n){
        xs[xc++]=in[i].x;
        xs[xc++]=in[i].y;
    }
    sort(xs,xs+xc);
    xc=unique(xs,xs+xc)-xs;
    REP(i,n){
        in[i].xi=lower_bound(xs,xs+xc,in[i].x)-xs;
        in[i].yi=lower_bound(xs,xs+xc,in[i].y)-xs;
    }
    MS1(tre);
    cov(1,0,xc-1,in[0].xi,in[0].yi-1,0);
   //printf("xc=%d\n",xc);
    REP1(i,1,n-1){
     //   printf("i=%d %d %d\n",i,in[i].xi,in[i].yi);
        int x1=que(1,0,xc-1,in[i].xi);
        int x2=que(1,0,xc-1,in[i].yi-1);
        if(x1!=-1)dc[i].insert(x1);
        if(x2!=-1)dc[i].insert(x2);
        cov(1,0,xc-1,in[i].xi,in[i].yi-1,i);
    }
    MS1(tre);
    cov(1,0,xc-1,in[n-1].xi,in[n-1].yi-1,n-1);
    PER1(i,n-2,0){
     //   printf("i=%d %d %d\n",i,in[i].xi,in[i].yi);
        int x1=que(1,0,xc-1,in[i].xi);
        int x2=que(1,0,xc-1,in[i].yi-1);
        if(x1!=-1)dc[x1].insert(i);
        if(x2!=-1)dc[x2].insert(i);
        cov(1,0,xc-1,in[i].xi,in[i].yi-1,i);
    }
    MS1(tre);
    cov(1,0,xc-1,in[0].xi,in[0].yi-1,0);
    dp[0]=2000000000;
    REP1(i,1,n-1){
        dp[i]=0;
        FOR(it,dc[i]){
            int j=*it;
            int xx=max(in[i].xi,in[j].xi);
            int yy=min(in[i].yi,in[j].yi);
           // printf("i=%d j=%d xx=%d yy=%d\n",i,j,xx,yy);
            if(que(1,0,xc-1,xx,yy-1)==-1)continue;
            dp[i]=max(dp[i],min(xs[yy]-xs[xx],dp[j]));
        }
        cov(1,0,xc-1,in[i].xi,in[i].yi-1,i);
        //puts("!");
    }
    PI(dp[n-1]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
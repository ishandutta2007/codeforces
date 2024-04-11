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
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(b);i>=(a);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y);
#define RIII(x,y,z) scanf("%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z);
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

int mod;
inline int add(int a,int b){
    a+=b;if(a>=mod)a-=mod;return a;
}
inline int mul(int a,int b){
    return (b*(LL)a)%mod;
}
struct XD{
    LL x[2][2];
    XD(){MS0(x);}
    XD operator*(const XD& b)const{
        XD c;
        REP(i,2)REP(j,2)REP(k,2)c.x[i][k]=add(c.x[i][k],mul(x[i][j],b.x[j][k]));
        return c;
    }
};
int fib(LL x){
    if(x<=2)return 1%mod;
    XD a,m;
    a.x[0][0]=a.x[1][1]=1;
    m.x[0][0]=m.x[0][1]=m.x[1][0]=1;
    x-=2;
    while(x){
        if(x%2)a=a*m;
        m=m*m;
        x/=2;
    }
    return add(a.x[0][0],a.x[0][1]);
}
LL l,r;
LL k;
inline bool f(LL x){
    return r/x-(l+x-1)/x+1>=k;
}
int main(){
    RI(mod);
    scanf("%I64d%I64d",&l,&r);
    scanf("%I64d",&k);
    /*
    //  For challenge.
    long long ll=1,rr=r;
    while(ll<rr){
        long long mm=(ll+rr+1)/2;
        if(r/mm-(l+mm-1)/mm+1>=k)ll=mm;
        else rr=mm-1;
    }
    */
    LL x;
    LL sr=max((LL)sqrt(r),1LL);
    LL ans=1;
    for(x=1;x<=sr;x++){
        if(f(x))ans=x;
    }
    for(x=1;x<=r/sr;x++){
        LL d=r/x;
        if(f(d))ans=max(ans,d);
    }
    printf("%d\n",fib(ans));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
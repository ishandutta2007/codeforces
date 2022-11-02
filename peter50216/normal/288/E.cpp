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
char ll[101000],rr[101000];
const int mod=1000000007;
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int sub(int a,int b){
    a-=b;
    if(a<0)a+=mod;
    return a;
}
inline int mul(int a,int b){
    return (a*(LL)b)%mod;
}
int a[101000],b[101000],c[101000],d[101000];
int p2[101000],p10[101000];
int n;
inline int solve(char* in){
    int A=mul(c[n],4);
    int ans=0;
    for(int i=0;i<n;i++){
        if(in[i]=='7'){
            int k=n-1-i;
            ans=add(ans,mul(mul(A,A),p2[k]));
            ans=add(ans,mul(A,add(mul(3,p10[k]),mul(2,a[k]))));
            ans=add(ans,b[k]);
            ans=add(ans,mul(mul(c[k],3),mul(p10[k],3)));
            A=add(A,mul(p10[k],3));
        }
    }
    return ans;
}
int main(){
    RS(ll);
    RS(rr);
    n=strlen(ll);
    p2[0]=1;
    for(int i=1;i<=n;i++)p2[i]=mul(p2[i-1],2);
    p10[0]=1;
    for(int i=1;i<=n;i++)p10[i]=mul(p10[i-1],10);
    a[0]=0;
    for(int i=1;i<=n;i++)a[i]=add(mul(a[i-1],2),mul(3,mul(p10[i-1],p2[i-1])));
    c[0]=0;
    for(int i=1;i<=n;i++)c[i]=add(mul(c[i-1],10),1);
    b[0]=0;
    for(int i=0;i<n;i++){
        b[i+1]=mul(2,b[i]);
        b[i+1]=add(b[i+1],mul(mul(3,p10[i]),mul(3,c[i])));
        b[i+1]=add(b[i+1],mul(mul(mul(3,p10[i]),mul(3,p10[i])),sub(p2[i],1)));
        b[i+1]=add(b[i+1],mul(mul(3,p10[i]),sub(mul(2,a[i]),mul(3,c[i]))));
    }
    //for(int i=0;i<=n;i++)printf("i=%d (a,b,c)=%3d %4d %3d\n",i,a[i],b[i],c[i]);
    printf("%d\n",sub(solve(rr),solve(ll)));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
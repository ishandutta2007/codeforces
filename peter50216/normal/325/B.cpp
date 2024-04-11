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

const LL INF=1000000000000000100LL;
inline LL add(LL a,LL b){
    LL c=a+b;
    if(c>=INF)return INF;
    return c;
}
inline LL mul(LL a,LL b){
    if(a==0||b==0)return 0;
    LL c=a*b;
    if(c/a==b)return min(c,INF);
    return INF;
}
inline LL f(LL a){
    if(a%2)return mul(a,(a-3)/2);
    else return mul(a/2,a-3);
}
int main(){
    LL n;
    scanf("%I64d",&n);
    LL mv=1;
    vector<LL> ans;
    for(int k=0;;k++){
        if(mv>=INF)break;
        LL l=0,r=INF;
        while(l<r){
            LL m=(l+r)/2;
            LL v=add(mul(mv,m),f(m));
            //printf("l=%I64d r=%I64d m=%I64d v=%I64d\n",l,r,m,v);
            if(v>=n)r=m;
            else l=m+1;
        }
        //printf("k=%d %I64d\n",k,l);
        LL v=add(mul(mv,l),f(l));
        if(v==n&&l%2==1)ans.PB(mv*l);
        mv=add(mv,mv);
    }
    sort(ans.begin(),ans.end());
    if(ans.empty())puts("-1");
    else REP(i,SZ(ans))printf("%I64d\n",ans[i]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
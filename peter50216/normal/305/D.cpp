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

const int mod=1000000007;
int p2[1010000];

inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int main(){
    p2[0]=1;
    REP1(i,1,1000000){
        p2[i]=add(p2[i-1],p2[i-1]);
    }
    DRIII(n,m,k);
    int a1=-1,la=-1;
    int cnt=0;
    REP(i,m){
        DRII(a,b);
        if(b-a==1)continue;
        if(b-a!=k+1){
            puts("0");
            return 0;
        }
        cnt++;
        if(a1==-1){
            a1=a;
        }else if(a-a1>=k+1){
            puts("0");
            return 0;
        }
        la=a;
    }
    int ans=0;
    REP1(i,1,n-k-1){
        if(a1!=-1){
            if(a1>=i&&la<i+k+1){
            }else continue;
        }
        int rem=k;
        if(rem>n-k-1-i)rem=n-k-1-i;
        rem-=cnt;
        if(a1==i)rem++;
        ans=add(ans,p2[rem]);
    }
    if(cnt==0)ans=add(ans,1);
    PI(ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
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

int allx[201000];
int xi[101000],yi[101000];
int cx[201000],cy[201000];
int main(){
    DRIII(n,m,k);
    int xc=0;
    REP(i,n){
        RI(xi[i]);
        allx[xc++]=xi[i];
    }
    REP(i,m){
        RI(yi[i]);
        allx[xc++]=yi[i];
    }
    sort(allx,allx+xc);
    xc=unique(allx,allx+xc)-allx;
    REP(i,n){
        xi[i]=lower_bound(allx,allx+xc,xi[i])-allx;
        cx[xi[i]]++;
    }
    REP(i,m){
        yi[i]=lower_bound(allx,allx+xc,yi[i])-allx;
        cy[yi[i]]++;
    }
    PER1(i,xc,1){
        cx[i-1]+=cx[i];
        cy[i-1]+=cy[i];
    }
    REP1(i,0,xc)if(cx[i]>cy[i]){
        puts("YES");
        return 0;
    }
    puts("NO");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
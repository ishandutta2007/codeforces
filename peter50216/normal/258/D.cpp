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

double p[1010][1010];
int a[1010];
int main(){
    DRII(n,m);
    REP(i,n){
        RI(a[i]);
        REP(j,i){
            if(a[j]>a[i]){
                p[j][i]=1;
            }else{
                p[i][j]=1;
            }
        }
    }
    REP(i,m){
        DRII(a,b);
        a--;b--;
        REP(j,n){
            if(j==a||j==b)continue;
            double s;
            s=(p[a][j]+p[b][j])/2;
            p[a][j]=p[b][j]=s;
            s=(p[j][a]+p[j][b])/2;
            p[j][a]=p[j][b]=s;
        }
        double s=(p[a][b]+p[b][a])/2;
        p[a][b]=p[b][a]=s;
    }
    double ans=0;
    REP(i,n)REP(j,i){
        ans+=p[j][i];
    }
    printf("%.10lf\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
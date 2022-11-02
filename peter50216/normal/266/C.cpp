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

int x[1010],y[1010];
int cnt[1010];
int out[3010][3],oc;
int main(){
    DRI(n);
    REP1(i,1,n-1)RII(x[i],y[i]);
    oc=0;
    REP1(i,1,n-1){
        int ii=-1;
        REP1(j,i,n-1)if(y[j]>=i)ii=j;
        if(ii==-1)break;
        if(i!=ii){
            swap(x[ii],x[i]);
            swap(y[ii],y[i]);
        }
        if(y[i]!=i){
            int yy=y[i];
            out[oc][0]=2;
            out[oc][1]=i;
            out[oc][2]=yy;
            oc++;
            REP1(j,i,n-1){
                if(y[j]==yy)y[j]=i;
                else if(y[j]==i)y[j]=yy;
            }
        }
        MS0(cnt);
        REP1(j,i,n-1){
            cnt[x[j]]++;
        }
        int xx=0;
        REP1(j,i,n)if(cnt[j]==0)xx=j;
        if(xx!=i){
            out[oc][0]=1;
            out[oc][1]=i;
            out[oc][2]=xx;
            oc++;
            REP1(j,i,n-1){
                if(x[j]==xx)x[j]=i;
                else if(x[j]==i)x[j]=xx;
            }
        }
    }
    printf("%d\n",oc);
    REP(i,oc)printf("%d %d %d\n",out[i][0],out[i][1],out[i][2]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
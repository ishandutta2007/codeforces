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
#define REPL(i,x) for(int i=0;x[i];i++)
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

vector<int> ed[110];
bool d[110];
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(a,b);
        a--;b--;
        ed[a].PB(b);
        ed[b].PB(a);
    }
    REP(i,n)d[i]=1;
    int cnt=0;
    while(1){
        vector<int> XD;
        REP(i,n){
            if(!d[i])continue;
            int cnt=0;
            FOR(it,ed[i]){
                cnt+=d[*it];
            }
            if(cnt==1)XD.PB(i);
        }
        if(XD.size()==0)break;
        FOR(it,XD)d[*it]=0;
        cnt++;
    }
    printf("%d\n",cnt);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
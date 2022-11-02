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
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y);
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
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

char in[110][10100];
int ans[110][10100];
const int INF=1000000000;
int main(){
    int n,m;
    RII(n,m);
    REP(i,n)scanf("%s",in[i]);
    REP(i,n)REP(j,m)ans[i][j]=INF;
    REP(i,n){
        bool f=0;
        REP(j,m){
            if(in[i][j]=='1'){
                f=1;break;
            }
        }
        if(!f){
            puts("-1");
            return 0;
        }
        int d=INF;
        REP(j,2*m){
            int jj=(j>=m?j-m:j);
            if(in[i][jj]=='1')d=0;
            else d++;
            ans[i][jj]=min(ans[i][jj],d);
        }
        d=INF;
        PER1(j,2*m-1,0){
            int jj=(j>=m?j-m:j);
            if(in[i][jj]=='1')d=0;
            else d++;
            ans[i][jj]=min(ans[i][jj],d);
        }
    }
    int ax=INF;
    REP(j,m){
        int c=0;
        REP(i,n)c+=ans[i][j];
        ax=min(ax,c);
    }
    printf("%d\n",ax);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
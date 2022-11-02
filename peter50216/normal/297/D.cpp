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

char in[2100][1010];
int out[1010][1010];
int main(){
    DRIII(h,w,k);
    REP(i,2*h-1)RS(in[i]);
    if(k==1){
        int c1=0,c=0;
        REP(i,2*h-1)REPL(j,in[i]){
            c++;
            if(in[i][j]=='E')c1++;
        }
        if(c1*4>=c*3){
            puts("YES");
            REP(i,h)REP(j,w)printf("1%c",SEP(j==w-1));
        }else puts("NO");
    }else{
        if(h>w){
            out[0][0]=0;
            REP1(i,1,h-1){
                if(in[i*2-1][0]=='N')out[i][0]=out[i-1][0]^1;
                else out[i][0]=out[i-1][0];
            }
            REP1(j,1,w-1){
                out[0][j]=0;
                REP1(i,1,h-1){
                    if(in[i*2-1][j]=='N')out[i][j]=out[i-1][j]^1;
                    else out[i][j]=out[i-1][j];
                }
                int c=0;
                REP(i,h){
                    if(in[i*2][j-1]=='N'&&out[i][j]==out[i][j-1])c++;
                    if(in[i*2][j-1]=='E'&&out[i][j]!=out[i][j-1])c++;
                }
                if(c>h-c){
                    REP(i,h)out[i][j]^=1;
                }
            }
        }else{
            out[0][0]=0;
            REP1(j,1,w-1){
                if(in[0][j-1]=='N')out[0][j]=out[0][j-1]^1;
                else out[0][j]=out[0][j-1];
            }
            REP1(i,1,h-1){
                out[i][0]=0;
                REP1(j,1,w-1){
                    if(in[i*2][j-1]=='N')out[i][j]=out[i][j-1]^1;
                    else out[i][j]=out[i][j-1];
                }
                int c=0;
                REP(j,w){
                    if(in[i*2-1][j]=='N'&&out[i][j]==out[i-1][j])c++;
                    if(in[i*2-1][j]=='E'&&out[i][j]!=out[i-1][j])c++;
                }
                if(c>w-c){
                    REP(j,w)out[i][j]^=1;
                }
            }
        }
        puts("YES");
        REP(i,h)REP(j,w)printf("%d%c",out[i][j]+1,SEP(j==w-1));
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
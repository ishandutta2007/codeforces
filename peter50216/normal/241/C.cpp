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
typedef pair<int,int> PII;
typedef long long LL;
// }}}

int sc[2][101000],bel[2][101000];
char tmp[10];
int used[110],uid;
int main(){
    int hl,hr,n;
    RIII(hl,hr,n);
    REP(i,n){
        int v,a,b;
        RI(v);
        scanf("%s",tmp);
        RII(a,b);
        int c;
        if(tmp[0]=='F')c=0;
        else c=1;
        REP1(j,a,b){
            sc[c][j]=v;
            bel[c][j]=i+1;
        }
    }
    const int W=100000;
    int ma=0;
    REP1(i,1,3000){
        int y1=hl,y2=i*100+(i%2?100-hr:hr);
        uid++;
        int ans=0;
        REP1(j,1,i){
            int x=W-W*(y2-100LL*j)/(y2-y1);
            //if(i==3){
          //      printf("j=%d x=%d\n",j,x);
         //   }
            int jj=j%2;
            if(bel[jj][x]==0){ans=0;break;}
            //if(i==3){
           //     printf("j=%d bel=%d sc=%d\n",j,bel[jj][x],sc[jj][x]);
           // }
            if(used[bel[jj][x]]==uid){
                ans=0;break;
            }
            used[bel[jj][x]]=uid;
            ans+=sc[jj][x];
        }
        //if(ans==135)printf("#1 %d y1=%d y2=%d\n",i,y1,y2);
        ma=max(ma,ans);
    }
    REP1(i,1,3000){
        int y1=hl,y2=-i*100+(i%2?100-hr:hr);
        uid++;
        int ans=0;
        //printf("i=%d %d %d\n",i,y1,y2);
        REP1(j,0,i-1){
            int x=W-W*(-100LL*j-y2)/(y1-y2);
            int jj=j%2;
            if(bel[jj][x]==0){ans=0;break;}
            if(used[bel[jj][x]]==uid){
                ans=0;break;
            }
            used[bel[jj][x]]=uid;
            ans+=sc[jj][x];
        }
        ma=max(ma,ans);
    }
    printf("%d\n",ma);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
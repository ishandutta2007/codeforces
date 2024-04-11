// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}
char in[2][101000];
int dis[2][101000];
int que[201000][2],qs,qe;
const int INF=1000000000;
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<2;i++)scanf("%s",in[i]);
    qs=qe=0;
    que[qe][0]=0;
    que[qe][1]=0;
    for(i=0;i<2;i++)for(j=0;j<=n;j++)dis[i][j]=INF;
    dis[0][0]=0;
    qe++;
    while(qs<qe){
        int x=que[qs][0],y=que[qs][1],d=dis[x][y];qs++;
        int xx,yy;
        xx=x;yy=y+1;
        if(yy>=n)yy=n;
        if(yy>=0&&(yy==n||in[xx][yy]!='X')){
            if(dis[xx][yy]==INF&&(yy==n||d+1<=yy)){
                dis[xx][yy]=d+1;
                que[qe][0]=xx;
                que[qe][1]=yy;
                qe++;
            }
        }
        xx=x;yy=y-1;
        if(yy>=n)yy=n;
        if(yy>=0&&(yy==n||in[xx][yy]!='X')){
            if(dis[xx][yy]==INF&&(yy==n||d+1<=yy)){
                dis[xx][yy]=d+1;
                que[qe][0]=xx;
                que[qe][1]=yy;
                qe++;
            }
        }
        xx=1-x;yy=y+k;
        if(yy>=n)yy=n;
        if(yy>=0&&(yy==n||in[xx][yy]!='X')){
            if(dis[xx][yy]==INF&&(yy==n||d+1<=yy)){
                dis[xx][yy]=d+1;
                que[qe][0]=xx;
                que[qe][1]=yy;
                qe++;
            }
        }
    }
    for(i=0;i<2;i++)if(dis[i][n]!=INF)break;
    puts(i<2?"YES":"NO");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
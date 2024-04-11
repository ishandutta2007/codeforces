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

int n,m;
int in[1610][1610];
int vis[1610][1610];
vector<PII> all;
int dx[8]={1,1,1,0,-1,-1,-1,0},dy[8]={-1,0,1,1,1,0,-1,-1};
int que[1610*1610][2],qs,qe;
int dis[1610][1610];
inline void bfs(int visid){
    while(qs<qe){
        int x=que[qs][0],y=que[qs][1];
        qs++;
        REP(k,8){
            int xx=x+dx[k],yy=y+dy[k];
            if(xx<0||xx>=n||yy<0||yy>=m||!in[xx][yy]||vis[xx][yy]==visid+1)continue;
            dis[xx][yy]=dis[x][y]+1;
            que[qe][0]=xx;que[qe][1]=yy;vis[xx][yy]=visid+1;qe++;
        }
    }
}
vector<int> ans;
inline void output(){
    REP(i,n){
        REP(j,m)printf("%d ",in[i][j]);puts("");
    }
}
int main(){
    RII(n,m);
    REP(i,n)REP(j,m)RI(in[i][j]);
    REP(i,n)REP(j,m)if(in[i][j]&&!vis[i][j]){
        all.clear();
        qs=qe=0;
        que[qe][0]=i;que[qe][1]=j;vis[i][j]=1;qe++;
        bfs(0);
        REP(k,qe)all.PB(MP(que[k][0],que[k][1]));
        qs=qe=0;
        REP(k,SZ(all)){
            int x=all[k].F,y=all[k].S;
            REP(s,8){
                int xx=x+dx[s],yy=y+dy[s];
                if(xx<0||xx>=n||yy<0||yy>=m||in[xx][yy]==0){
                    que[qe][0]=x;que[qe][1]=y;vis[x][y]=2;dis[x][y]=1;qe++;
                }
            }
        }
        bfs(1);
        qs=qe=0;
        REP(k,SZ(all)){
            int x=all[k].F,y=all[k].S;
            if(dis[x][y]>4){
                //in[x][y]=2;
                que[qe][0]=x;que[qe][1]=y;vis[x][y]=3;dis[x][y]=1;qe++;
            }
        }
        bfs(2);
        int visid=10;
        int cnt=0;
        REP(k,SZ(all)){
            int x=all[k].F,y=all[k].S;
            if(dis[x][y]<=8){
                in[x][y]=0;
            }
        }
        REP(k,SZ(all)){
            int x=all[k].F,y=all[k].S;
            if(in[x][y]&&vis[x][y]==3){
                qs=qe=0;
                que[qe][0]=x;que[qe][1]=y;vis[x][y]=visid+1;qe++;
                bfs(visid);
                visid++;
                cnt++;
            }
        }
        ans.PB(cnt);
    }
    sort(ans.begin(),ans.end());
    PI(SZ(ans));
    REP(i,SZ(ans))printf("%d%c",ans[i],SEP(i==SZ(ans)-1));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
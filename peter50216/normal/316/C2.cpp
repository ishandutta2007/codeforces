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

const int INF=1000000000;
int in[90][90];
int id[90][90];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int src,sink;
struct XD{
    int x,y;
    int ca,co;
    int revc;
    XD(){}
    XD(int x,int y,int ca,int co,int revc):x(x),y(y),ca(ca),co(co),revc(revc){}
};
vector<XD> ed[6500];
inline void adde(int x,int y,int ca,int co){
    int v1=ed[x].size(),v2=ed[y].size();
    ed[x].PB(XD(x,y,ca,co,v2));
    ed[y].PB(XD(y,x,0,-co,v1));
}
int dis[6500];
int pre[6500];
int que[6500],qs,qe;
bool inq[6500];
inline void push(int a){
    if(inq[a])return;
    inq[a]=1;
    que[qe++]=a;
    if(qe==6500)qe=0;
}
inline int pop(){
    int a=que[qs++];
    if(qs==6500)qs=0;
    inq[a]=0;
    return a;
}
inline int spfa(){
    int n=sink+1;
    REP(i,n)dis[i]=INF;
    dis[src]=0;
    qs=qe=0;
    push(src);
    while(qs!=qe){
        int np=pop();
        for(int i=0;i<ed[np].size();i++){
            if(!ed[np][i].ca)continue;
            int y=ed[np][i].y;
            if(dis[y]>dis[np]+ed[np][i].co){
                dis[y]=dis[np]+ed[np][i].co;
                pre[y]=ed[np][i].revc;
                push(y);
            }
        }
    }
    if(dis[sink]==INF)return -1;
    int np=sink;
    int ret=0;
    while(np!=src){
        int y=ed[np][pre[np]].y;
        ed[np][pre[np]].ca++;
        ed[y][ed[np][pre[np]].revc].ca--;
        ret+=ed[y][ed[np][pre[np]].revc].co;
        np=y;
    }
    return ret;
}
inline int mcmf(){
    int ret=0,c;
    while((c=spfa())!=-1)ret+=c;
    return ret;
}
int main(){
    DRII(n,m);
    REP(i,n)REP(j,m)RI(in[i][j]);
    src=0;sink=n*m+1;
    int i1=1,i2=n*m/2+1;
    REP(i,n)REP(j,m){
        if((i+j)%2)id[i][j]=i1++;
        else id[i][j]=i2++;
    }
    REP(i,n)REP(j,m){
        if((i+j)%2)adde(0,id[i][j],1,0);
        else adde(id[i][j],n*m+1,1,0);
    }
    REP(i,n)REP(j,m){
        if((i+j)%2){
            REP(k,4){
                int ii=i+dx[k],jj=j+dy[k];
                if(ii>=0&&ii<n&&jj>=0&&jj<m){
                    adde(id[i][j],id[ii][jj],1,(in[i][j]==in[ii][jj]?0:1));
                }
            }
        }
    }
    PI(mcmf());
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
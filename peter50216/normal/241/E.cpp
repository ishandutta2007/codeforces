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

int n,m;
struct XD{
    int y,id,l;
    XD(int yy,int ii){
        y=yy;
        id=ii;
        l=1;
    }
};
int dl[1010],dr[1010];
vector<XD> ed[1010];
vector<XD> re[1010];
int ans[5010];
int vis[1010];
//int top[1010],tid;
//int vis[1010];
//int u[1010];
//int d[1010];
inline void dfs(int np){
    if(vis[np]&1)return;
    vis[np]|=1;
    REP(i,SZ(ed[np])){
        int y=ed[np][i].y;
        dfs(y);
    }
}
inline void rdfs(int np){
    if(vis[np]&2)return;
    vis[np]|=2;
    REP(i,SZ(re[np])){
        int y=re[np][i].y;
        rdfs(y);
    }
}
int que[1010],qs,qe;
bool inq[1010];
inline void push(int a){
    if(inq[a])return;
    inq[a]=1;
    que[qe++]=a;
    if(qe==1010)qe=0;
}
inline int pop(){
    int a=que[qs++];
    inq[a]=0;
    if(qs==1010)qs=0;
    return a;
}
int d[1010];
int main(){
    RII(n,m);
    REP(i,m){
        int a,b;
        RII(a,b);
        a--;b--;
        ed[a].PB(XD(b,i));
        re[b].PB(XD(a,i));
    }
    REP(i,n){
        dl[i]=-1000000;
        dr[i]=1000000;
    }
    dfs(0);rdfs(n-1);
    dl[0]=dr[0]=0;
    qs=qe=0;
    push(0);
    while(qs!=qe){
        int np=pop();
        REP(j,SZ(ed[np])){
            int y=ed[np][j].y;
            if(vis[y]!=3)continue;
            if(d[y])continue;
            int ll=dl[y],rr=dr[y];
            dl[y]=max(dl[y],dl[np]+1);
            dr[y]=min(dr[y],dr[np]+2);
            if(dl[y]>dr[y]){
                d[y]=1;
                continue;
            }
            if(ll!=dl[y]||rr!=dr[y]){
                push(y);
            }
        }
        REP(j,SZ(re[np])){
            int y=re[np][j].y;
            if(vis[y]!=3)continue;
            if(d[y])continue;
            int ll=dl[y],rr=dr[y];
            dl[y]=max(dl[y],dl[np]-2);
            dr[y]=min(dr[y],dr[np]-1);
            if(dl[y]>dr[y]){
                d[y]=1;
                continue;
            }
            if(ll!=dl[y]||rr!=dr[y]){
                push(y);
            }
        }
    }
    REP(i,n)if(d[i])push(i);
    while(qs!=qe){
        int np=pop();
        REP(j,SZ(ed[np])){
            int y=ed[np][j].y;
            if(d[y])continue;
            d[y]=1;
            push(y);
        }
    }
    if(!d[n-1]){
        puts("Yes");
        REP(i,n){
            if(vis[i]!=3)continue;
            if(d[i])continue;
            REP(j,SZ(ed[i])){
                int y=ed[i][j].y;
                if(vis[y]!=3)continue;
                if(d[y])continue;
                ed[i][j].l=dl[y]-dl[i];
            }
        }
        REP(i,n){
            REP(j,SZ(ed[i])){
                ans[ed[i][j].id]=ed[i][j].l;
            }
        }
        REP(i,m)printf("%d\n",ans[i]);
    }else puts("No");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
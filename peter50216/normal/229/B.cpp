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

struct XD{
    int y,c;
    XD(int yy=0,int cc=0):y(yy),c(cc){}
};
vector<XD> ed[101000];
map<int,int> nxt[101000];
int in[101000];
int dis[101000];
const int INF=1050000000;
inline int fn(int x,int t){
    map<int,int>::iterator it=nxt[x].find(t);
    if(it==nxt[x].end())return t;
    return it->S;
}
int main(){
    int n,m;
    RII(n,m);
    REP(i,m){
        DRIII(a,b,c);
        a--;b--;
        ed[a].PB(XD(b,c));
        ed[b].PB(XD(a,c));
    }
    REP(i,n){
        DRI(c);
        REP(j,c)RI(in[j]);
        int nx;
        PER(j,c){
            if(j==c-1||in[j+1]!=in[j]+1)nx=in[j]+1;
            nxt[i][in[j]]=nx;
        }
    }
    REP(i,n)dis[i]=INF;
    dis[0]=0;
    priority_queue<PII> pq;
    pq.push(MP(0,0));
    while(!pq.empty()){
        int np=pq.top().S,d=-pq.top().F;
        pq.pop();
        if(dis[np]!=d)continue;
        int ot=fn(np,dis[np]);
        REP(i,ed[np].size()){
            int y=ed[np][i].y,d=ed[np][i].c;
            if(ot+d<dis[y]){
                dis[y]=ot+d;
                pq.push(MP(-dis[y],y));
            }
        }
    }
    if(dis[n-1]==INF)puts("-1");
    else printf("%d\n",dis[n-1]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
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

int vx,vy,sx,sy;
int mid=110;
int que[41000][2],qs,qe;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
set<PII> rock;
inline bool ins(int x,int y){return x<=110&&x>=-110&&y<=110&&y>=-110;}
set<PII> vis;
vector<int> mv;
vector<int> ans;
inline bool dfs(int sx,int sy){
    if(vis.count(MP(sx,sy)))return 0;
    vis.insert(MP(sx,sy));
    REP(i,4){
        int xx=sx+dx[i],yy=sy+dy[i];
        if(rock.count(MP(xx,yy)))continue;
        if(!ins(xx,yy))return 1;
        if(dfs(xx,yy))return 1;
    }
    return 0;
}
inline bool to(int sx,int sy,int tx,int ty){
    if(sx==tx&&sy==ty)return 1;
    if(vis.count(MP(sx,sy)))return 0;
    vis.insert(MP(sx,sy));
    REP(i,4){
        int xx=sx+dx[i],yy=sy+dy[i];
        if(rock.count(MP(xx,yy)))continue;
        if(!ins(xx,yy))return 0;
        mv.PB(i);
        if(to(xx,yy,tx,ty))return 1;
        mv.pop_back();
    }
    return 0;
}
inline void move(int d){
    ans.PB(d);
    vx+=dx[d];
    vy+=dy[d];
    if(!rock.count(MP(sx+dx[d],sy+dy[d]))){
        sx+=dx[d];sy+=dy[d];
    }
}
inline void move(int d,int c){
    while(c--)move(d);
}
inline void move(const vector<int>& seq){
    REP(i,SZ(seq))move(seq[i]);
}
int main(){
    RII(vx,vy);
    RII(sx,sy);
    DRI(m);
    if(m==0){
        puts("-1");
        return 0;
    }
    while(m--){
        DRII(x,y);
        rock.insert(MP(x,y));
    }
    vis.clear();
    if(dfs(vx,vy)){//open
        vis.clear();
        if(!dfs(sx,sy)){
            puts("-1");
            return 0;
        }
        vis.clear();mv.clear();
        to(vx,vy,110,110);
        move(mv);
        move(0,1000);
        move(1,1000);
        if(ins(sx,sy)){
            vis.clear();mv.clear();
            to(sx,sy,110,110);
            move(mv);
        }
        move(0,1000);
        move(1,1000);
        PII maxx=*rock.begin(),
            minx=*rock.begin(),
            maxy=*rock.begin(),
            miny=*rock.begin();
        FOR(it,rock){
            if(it->F>maxx.F)maxx=*it;
            if(it->F<minx.F)minx=*it;
            if(it->S>maxy.S)maxy=*it;
            if(it->S<miny.S)miny=*it;
        }
        if(vx>sx){
            while(sy>maxx.S)move(3);
            while(vx>sx)move(2);
            move(0,1000);
            move(1,1000);
        }else{
            while(sx>-200)move(2);
            while(sy>minx.S)move(3);
            while(vx<sx)move(0);
            move(1,2000);
            move(0,2000);
        }
        if(vy>sy){
            while(sx>maxy.F)move(2);
            while(vy>sy)move(3);
        }else{
            while(sy>-200)move(3);
            while(sx>miny.F)move(2);
            while(vy<sy)move(1);
        }
    }else{
        vis.clear();mv.clear();
        if(!to(vx,vy,sx,sy)){
            puts("-1");
            return 0;
        }
        while(vx!=sx||vy!=sy){
            vis.clear();mv.clear();
            to(vx,vy,sx,sy);
            move(mv);
        }
    }
    REP(i,SZ(ans))printf("%c","RULD"[ans[i]]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
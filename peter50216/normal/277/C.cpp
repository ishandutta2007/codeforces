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
struct XD{
    int x,f;
    XD(int xx=0,int ff=0):x(xx),f(ff){}
    bool operator<(const XD& b)const{
        return x==b.x?f>b.f:x<b.x;
    }
};
map<int,vector<XD> > allx,ally;
map<int,vector<PII> > segx,segy;
map<int,int> lenx,leny;
inline vector<PII> toseg(vector<XD>& v,int ma){
    vector<PII> ret;
    sort(v.begin(),v.end());
    v.PB(XD(ma,1));
    int d=0;
    int p=0;
    REP(i,SZ(v)){
        if(v[i].x!=p&&d==0){
            ret.PB(MP(p,v[i].x));
        }
        d+=v[i].f;
        if(d==0){
            p=v[i].x;
        }
    }
    return ret;
}
inline int totl(const vector<PII>& v){
    int ans=0;
    FOR(it,v)ans+=it->S-it->F;
    return ans;
}
inline int solve(const vector<PII>& v,int len){
    REP(i,SZ(v)){
        if(v[i].S-v[i].F>=len){
            return v[i].F+len;
        }
        len-=(v[i].S-v[i].F);
    }
}
int main(){
    DRIII(n,m,k);
    REP(i,k){
        DRII(x1,y1);
        DRII(x2,y2);
        if(x1==x2){
            if(y1>y2)swap(y1,y2);
            allx[x1].PB(XD(y1,1));
            allx[x1].PB(XD(y2,-1));
        }else{
            if(x1>x2)swap(x1,x2);
            ally[y1].PB(XD(x1,1));
            ally[y1].PB(XD(x2,-1));
        }
    }
    if(allx.size()<n-1){
        int x=1;
        while(allx.count(x))x++;
        allx[x].clear();
    }
    if(ally.size()<m-1){
        int y=1;
        while(ally.count(y))y++;
        ally[y].clear();
    }
    int ans=0;
    FOR(it,allx){
        int x=it->F;
        segx[x]=toseg(it->S,m);
        lenx[x]=totl(segx[x]);
        ans^=lenx[x];
        //printf("x=%d:\n",x);
        //FOR(i2,segx[x])printf("%d %d\n",i2->F,i2->S);
    }
    FOR(it,ally){
        int y=it->F;
        segy[y]=toseg(it->S,n);
        leny[y]=totl(segy[y]);
        ans^=leny[y];
        //printf("y=%d:\n",y);
        //FOR(i2,segy[y])printf("%d %d\n",i2->F,i2->S);
    }
    if((n-1)%2!=SZ(allx)%2)ans^=m;
    if((m-1)%2!=SZ(ally)%2)ans^=n;
    if(ans==0)puts("SECOND");
    else{
        puts("FIRST");
        FOR(it,allx){
            int x=it->F;
            if((lenx[x]^ans)<lenx[x]){
                int t=solve(segx[x],lenx[x]-(lenx[x]^ans));
                printf("%d 0 %d %d\n",x,x,t);
                return 0;
            }
        }
        FOR(it,ally){
            int y=it->F;
            if((leny[y]^ans)<leny[y]){
                int t=solve(segy[y],leny[y]-(leny[y]^ans));
                printf("0 %d %d %d\n",y,t,y);
                return 0;
            }
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
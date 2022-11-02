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

vector<PII> ed[5400];
int n,k;
int x[51];
const int mod=1000000007;
int bin[55][55];
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int mul(int a,int b){
    return (a*(LL)b)%mod;
}
int c1,c2;
inline int id(int x,int y,int z){
    return x*(c1+1)*(c2+1)+y*(c2+1)+z;
}
int dis[5400];
int way[5400];
int que[5400],qs,qe;
PII solve(){
    //printf("c1=%d c2=%d k=%d\n",c1,c2,k);
    REP1(i,0,c1)REP1(j,0,c2){
        REP1(ii,0,i)REP1(jj,0,j){
            if(ii+jj*2>k||ii+jj==0)continue;
            ed[id(0,i,j)].PB(MP(id(1,i-ii,j-jj),mul(bin[i][ii],bin[j][jj])));
        }
    }
    REP1(i,0,c1)REP1(j,0,c2){
        REP1(ii,0,c1-i)REP1(jj,0,c2-j){
            if(ii+jj*2>k||ii+jj==0)continue;
            ed[id(1,i,j)].PB(MP(id(0,i+ii,j+jj),mul(bin[c1-i][ii],bin[c2-j][jj])));
        }
    }
    MS1(dis);
    MS0(way);
    dis[id(0,c1,c2)]=0;
    way[id(0,c1,c2)]=1;
    que[qe++]=id(0,c1,c2);
    while(qs<qe){
        int np=que[qs++];
        REP(i,SZ(ed[np])){
            int y=ed[np][i].F,c=ed[np][i].S;
          //  printf("%d -> %d = %d\n",np,y,c);
            if(dis[y]==-1||dis[y]==dis[np]+1){
                if(dis[y]==-1)que[qe++]=y;
                dis[y]=dis[np]+1;
                way[y]=add(way[y],mul(c,way[np]));
            }
        }
    }
    if(dis[id(1,0,0)]==-1)return MP(-1,0);
    return MP(dis[id(1,0,0)],way[id(1,0,0)]);
}
int main(){
    bin[0][0]=1;
    REP1(i,1,54){
        bin[i][0]=bin[i][i]=1;
        REP1(j,1,i-1)bin[i][j]=add(bin[i-1][j],bin[i-1][j-1]);
    }
    RII(n,k);
    REP(i,n)RI(x[i]);
    k/=50;
    REP(i,n){
        x[i]/=50;
        if(x[i]==1)c1++;
        else c2++;
    }
    PII r=solve();
    printf("%d\n%d\n",r.F,r.S);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
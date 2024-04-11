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

map<int,int> nc;
int mul[30];
inline int dpf(int x){
    pair<map<int,int>::iterator,bool> p=nc.insert(MP(x,0));
    if(!p.S)return p.F->S;
    int xx=x;
    int v[31];
    REP(i,31)v[i]=0;
    for(int i=0;i<30&&xx;i++){
        if((xx&(1<<i))==0)continue;
       // printf("x=%d i=%d nex=%d\n",x,i,x&~mul[i]);
        v[dpf(x&~mul[i])]=1;
        xx-=(1<<i);
    }
    int r=0;
    while(v[r])r++;
    //printf("%d %d\n",x,r);
    return p.F->S=r;
}
int nt[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
inline int nim(int x){
    if(x>=30)while(1);
    return nt[x];
//    return dpf((1<<x)-1);
}
int main(){
    REP(i,30){
        int x=0;
        for(int j=i+1;j<=30;j+=(i+1)){
            x|=(1<<(j-1));
        }
        mul[i]=x;
    }
    nc[0]=0;
    DRI(n);
    set<int> used;
    int ans=0;
    int i;
    for(i=1;i*i<=n;i++){
        if(i==1){
            ans^=1;continue;
        }
        if(used.count(i))continue;
        LL j=i;
        int c=0;
        while(j<=n){
            c++;
            used.insert(j);
            j*=i;
        }
        ans^=nim(c);
    }
    int cu=0;
    FOR(it,used)if(*it>=i)cu++;
    if(((n-i+1)-cu)%2)ans^=1;
    puts(ans?"Vasya":"Petya");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
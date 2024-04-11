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


const int mod=1000000000;
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int mul(int a,int b){
    return (a*(LL)b)%mod;
}
int f1[201000];
int f2[201000];
int sf1[201000],sf2[201000];
int t1[1200000],t2[1200000];
int ta[1200000];
inline void down(int np,int l,int r){
    int m=(l+r)/2;
    if(ta[np]){
        t1[np*2]=add(t1[np*2],mul(ta[np],sf1[m-l+1]));
        t2[np*2]=add(t2[np*2],mul(ta[np],sf2[m-l+1]));
        t1[np*2+1]=add(t1[np*2+1],mul(ta[np],sf1[r-(m+1)+1]));
        t2[np*2+1]=add(t2[np*2+1],mul(ta[np],sf2[r-(m+1)+1]));
        ta[np*2]=add(ta[np*2],ta[np]);
        ta[np*2+1]=add(ta[np*2+1],ta[np]);
        ta[np]=0;
    }
}
inline void merge(int& a,int a1,int a2,int& b,int b1,int b2,int x){
    a=add(a1,add(mul(f1[x+1],a2),mul(f1[x],b2)));
    b=add(b1,add(mul(f2[x+1],a2),mul(f2[x],b2)));
}
inline void up(int np,int l,int r){
    int m=(l+r)/2;
    merge(t1[np],t1[np*2],t1[np*2+1],t2[np],t2[np*2],t2[np*2+1],m-l+1);
}
inline void change(int np,int l,int r,int x,int c){
    if(l==r){
        t1[np]=0;
        t2[np]=c;
        ta[np]=0;
        return;
    }
    down(np,l,r);
    int m=(l+r)/2;
    if(x<=m)change(np*2,l,m,x,c);
    else change(np*2+1,m+1,r,x,c);
    up(np,l,r);
}
inline void addv(int np,int l,int r,int x,int y,int d){
    if(x==l&&y==r){
        t1[np]=add(t1[np],mul(sf1[r-l+1],d));
        t2[np]=add(t2[np],mul(sf2[r-l+1],d));
        ta[np]=add(ta[np],d);
        return;
    }
    down(np,l,r);
    int m=(l+r)/2;
    if(x<=m&&y>m){
        addv(np*2,l,m,x,m,d);
        addv(np*2+1,m+1,r,m+1,y,d);
    }else if(x>m)addv(np*2+1,m+1,r,x,y,d);
    else addv(np*2,l,m,x,y,d);
    up(np,l,r);
}
inline pair<int,int> query(int np,int l,int r,int x,int y){
    if(x==l&&y==r)return MP(t1[np],t2[np]);
    down(np,l,r);
    int m=(l+r)/2;
    pair<int,int> p;
    if(x<=m&&y>m){
        pair<int,int> p1=query(np*2,l,m,x,m);
        pair<int,int> p2=query(np*2+1,m+1,r,m+1,y);
        merge(p.F,p1.F,p2.F,p.S,p1.S,p2.S,m-x+1);
    }else if(x>m)p=query(np*2+1,m+1,r,x,y);
    else p=query(np*2,l,m,x,y);
    up(np,l,r);
    return p;
}
int main(){
    DRII(n,m);
    f1[0]=0;
    f1[1]=1;
    REP1(i,2,200100)f1[i]=add(f1[i-1],f1[i-2]);
    f2[0]=1;
    f2[1]=0;
    REP1(i,2,200100)f2[i]=add(f2[i-1],f2[i-2]);
    sf1[0]=sf2[0]=0;
    REP1(i,1,200101)sf1[i]=add(sf1[i-1],f1[i-1]);
    REP1(i,1,200101)sf2[i]=add(sf2[i-1],f2[i-1]);
    REP(i,n){
        DRI(v);
        change(1,0,n-1,i,v);
    }
    while(m--){
        DRI(t);
        if(t==1){
            DRII(x,v);
            x--;
            change(1,0,n-1,x,v);
        }else if(t==2){
            DRII(a,b);
            a--;b--;
            PII p=query(1,0,n-1,a,b);
            printf("%d\n",add(p.F,p.S));
        }else{
            DRIII(a,b,d);
            a--;b--;
            addv(1,0,n-1,a,b,d);
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
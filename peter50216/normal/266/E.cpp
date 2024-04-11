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
#define ALL(x) (x).begin(),(x).end()
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
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#else
#define FILEIO(x) ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

const int mod=1000000007;
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int sub(int a,int b){
    a-=b;
    if(a<0)a+=mod;
    return a;
}
inline int mul(int a,int b){
    return (a*(LL)b)%mod;
}
inline int reg(int c){
    c%=mod;
    if(c<0)c+=mod;
    return c;
}
int pob[6][110000];
int tre[6][540000];
int cov[6][540000];
bool covd[6][540000];
int pobs[6][110000];
inline int sumd(int x,int y,int k){//x^k+...+y^k
    return sub(pobs[k][y],pobs[k][x-1]);
}
inline void down(int k,int np,int l,int r){
    if(covd[k][np]){
        int c=cov[k][np];
        int m=(l+r)/2;
        covd[k][np]=0;
        covd[k][np*2]=covd[k][np*2+1]=1;
        cov[k][np*2]=cov[k][np*2+1]=c;
        tre[k][np*2]=mul(sumd(l,m,k),c);
        tre[k][np*2+1]=mul(sumd(m+1,r,k),c);
    }
}
inline void up(int k,int np){
    tre[k][np]=add(tre[k][np*2],tre[k][np*2+1]);
}
inline int que(int np,int l,int r,int x,int y,int k){
    if(l==x&&r==y){
        return tre[k][np];
    }
    int m=(l+r)/2;
    down(k,np,l,r);
    if(x<=m&&y>m){
        return add(que(np*2,l,m,x,m,k),que(np*2+1,m+1,r,m+1,y,k));
    }else if(x>m){
        return que(np*2+1,m+1,r,x,y,k);
    }else{
        return que(np*2,l,m,x,y,k);
    }
}
inline void covf(int np,int l,int r,int x,int y,int k,int c){
    //printf("%d %d %d %d %d %d %d\n",np,l,r,x,y,k,c);
    if(l==x&&r==y){
        cov[k][np]=c;
        covd[k][np]=1;
        tre[k][np]=mul(sumd(l,r,k),c);
        return;
    }
    down(k,np,l,r);
    int m=(l+r)/2;
    if(x<=m&&y>m){
        covf(np*2,l,m,x,m,k,c);
        covf(np*2+1,m+1,r,m+1,y,k,c);
    }else if(x>m){
        covf(np*2+1,m+1,r,x,y,k,c);
    }else{
        covf(np*2,l,m,x,y,k,c);
    }
    up(k,np);
}
char in[100];
int s[6];
int bin[6][6];
int main(){
    DRII(n,m);
    REP(k,6){
        pobs[k][0]=0;
        REP1(i,1,n){
            int x=1;
            REP(kk,k)x=mul(x,i);
            pob[k][i]=x;
            pobs[k][i]=add(pobs[k][i-1],pob[k][i]);
        }
    }
    bin[0][0]=1;
    REP1(k,1,5){
        bin[k][0]=bin[k][k]=1;
        REP1(i,1,k-1)bin[k][i]=add(bin[k-1][i],bin[k-1][i-1]);
    }
    REP1(i,1,n){
        DRI(a);
        a=reg(a);
        REP(k,6){
            covf(1,1,n,i,i,k,a);
        }
    }
    while(m--){
        RS(in);
        DRIII(l,r,x);
        if(in[0]=='='){
            x=reg(x);
            REP(k,6){
                covf(1,1,n,l,r,k,x);
            }
        }else{
            REP(k,6)s[k]=que(1,1,n,l,r,k);
            int c=reg(-l+1);
            int su=0;
            int cp=1;
            REP1(i,0,x){
                int r=reg(bin[x][i]);
                r=mul(r,s[x-i]);
                r=mul(r,cp);
                cp=mul(cp,c);
                su=add(su,r);
            }
            printf("%d\n",su);
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
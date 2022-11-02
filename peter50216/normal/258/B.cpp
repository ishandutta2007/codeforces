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

int ans;
const int mod=1000000007;
inline void add(int x){
    ans+=x;
    if(ans>=mod)ans-=mod;
}
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int n;
int u[10];
int cnt[10];
int xx[10];
inline void dfs(int np,int s){
    if(np==7){
        MS0(xx);
        LL t=1;
        REP(i,7){
            if(xx[u[i]]==cnt[u[i]]){
                t=0;break;
            }
            t=(t*(cnt[u[i]]-xx[u[i]]))%mod;
            xx[u[i]]++;
        }
        add(t);
        return;
    }
    REP1(i,0,s-1){
        u[np]=i;
        dfs(np+1,s-i);
    }
}
inline int cnt47(int x){
    if(x==0)return 0;
    int xx=x%10;
    return cnt47(x/10)+(xx==4||xx==7?1:0);
}
inline vector<LL> run(int x){
    vector<LL> ret(10);
    if(x<10){
        REP1(i,0,x){
            if(i==4||i==7)ret[1]++;
            else ret[0]++;
        }
    }else{
        int c=cnt47(x/10);
        vector<LL> rr=run(x/10-1);
        REP(i,10)ret[i]=(rr[i]*8)%mod;
        REP1(i,1,9)ret[i]=(ret[i]+rr[i-1]*2)%mod;
        REP1(i,0,x%10){
            if(i==4||i==7)ret[c+1]=add(ret[c+1],1);
            else ret[c]=add(ret[c],1);
        }
    }
    return ret;
}
int main(){
    RI(n);
    vector<LL> r=run(n);
    REP(i,10){
        cnt[i]=r[i];
    }
    cnt[0]--;
    REP1(i,1,9){
        u[0]=i;
        dfs(1,i);
    }
    printf("%d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
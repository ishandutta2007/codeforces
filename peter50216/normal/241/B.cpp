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

const int mod=1000000007;
int in[50010];
int len[40];
vector<int> v1[40][50010],v2[40][50010];
int cnt1[40][50010][2],cnt2[40][50010][2];
inline int g(int x,int d){
    return (x>>(31-d))&1;
}
inline int col(const vector<int>& r,vector<int>& to,int a,int d){
    REP(i,SZ(r)){
        if(a==g(in[r[i]],d))to.PB(r[i]);
    }
}
inline int solve(int d,LL cnt){
    if(d==32)return 0;
    int i,j,ret=0;
    LL dif=0;
    for(i=0;i<len[d];i++){
        for(j=0;j<SZ(v1[d][i]);j++){
            cnt1[d][i][g(in[v1[d][i][j]],d)]++;
        }
        for(j=0;j<SZ(v2[d][i]);j++){
            cnt2[d][i][g(in[v2[d][i][j]],d)]++;
        }
        dif+=cnt1[d][i][0]*1LL*cnt2[d][i][1];
        dif+=cnt1[d][i][1]*1LL*cnt2[d][i][0];
    }
    if(dif<cnt){
        ret=(ret+dif*(1LL<<(31-d)))%mod;
        for(int dd=d+1;dd<32;dd++){
            for(i=0;i<len[d];i++){
                LL c1[2][2]={{0,0},{0,0}},c2[2][2]={{0,0},{0,0}};
                for(j=0;j<SZ(v1[d][i]);j++){
                    c1[g(in[v1[d][i][j]],d)][g(in[v1[d][i][j]],dd)]++;
                }
                for(j=0;j<SZ(v2[d][i]);j++){
                    c2[g(in[v2[d][i][j]],d)][g(in[v2[d][i][j]],dd)]++;
                }
                ret=(ret+(c1[1][1]*c2[0][0]+c1[0][1]*c2[1][0]+c1[1][0]*c2[0][1]+c1[0][0]*c2[1][1])*(1LL<<(31-dd)))%mod;
            }
        }
        cnt-=dif;
        for(i=0;i<len[d];i++){
            if(cnt1[d][i][0]&&cnt2[d][i][0]){
                col(v1[d][i],v1[d+1][len[d+1]],0,d);
                col(v2[d][i],v2[d+1][len[d+1]],0,d);
                len[d+1]++;
            }
            if(cnt1[d][i][1]&&cnt2[d][i][1]){
                col(v1[d][i],v1[d+1][len[d+1]],1,d);
                col(v2[d][i],v2[d+1][len[d+1]],1,d);
                len[d+1]++;
            }
        }
    }else{
        ret=(ret+cnt*(1LL<<(31-d)))%mod;
        for(i=0;i<len[d];i++){
            if(cnt1[d][i][0]&&cnt2[d][i][1]){
                col(v1[d][i],v1[d+1][len[d+1]],0,d);
                col(v2[d][i],v2[d+1][len[d+1]],1,d);
                len[d+1]++;
            }
            if(cnt1[d][i][1]&&cnt2[d][i][0]){
                col(v1[d][i],v1[d+1][len[d+1]],1,d);
                col(v2[d][i],v2[d+1][len[d+1]],0,d);
                len[d+1]++;
            }
        }
    }
    ret+=solve(d+1,cnt);
    if(ret>=mod)ret-=mod;
    return ret;
}
int main(){
    int n,m;
    RII(n,m);
    REP(i,n)RI(in[i]);
    LL mm=m*2LL;
    vector<int> tmp;
    tmp.reserve(n);
    REP(i,n)tmp.PB(i);
    v1[0][0]=v2[0][0]=tmp;
    len[0]=1;
    printf("%d\n",(solve(0,mm)*((mod+1LL)/2))%mod);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
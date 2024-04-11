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
#define PER1(i,a,b) for(int i=(b);i>=(a);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y);
#define RIII(x,y,z) scanf("%d%d",&x,&y,&z)
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

bool rr[110],rc[110];
int sr[110],sc[110];
int in[110][110];

int main(){
    DRII(n,m);
    REP(i,n)REP(j,m)RI(in[i][j]);
    while(1){
        MS0(sr);
        MS0(sc);
        REP(i,n)REP(j,m){
            int a=in[i][j];
            if(rr[i]^rc[j])a=-a;
            sr[i]+=a;
            sc[j]+=a;
        }
        bool f=0;
        int mi=0,mp=0,mp2=0;
        REP(i,n)if(sr[i]<mi){
            mp=i;mp2=0;
            mi=sr[i];
            f=1;
        }
        REP(j,m)if(sc[j]<0){
            f=1;
            mp=j;mp2=1;mi=sc[j];
        }
        if(!f)break;
        if(mp2)rc[mp]^=1;
        else rr[mp]^=1;
    }
    int c1=0,c2=0;
    REP(i,n)if(rr[i])c1++;
    printf("%d",c1);
    REP(i,n)if(rr[i])printf(" %d",i+1);
    puts("");
    REP(i,m)if(rc[i])c2++;
    printf("%d",c2);
    REP(i,m)if(rc[i])printf(" %d",i+1);
    puts("");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
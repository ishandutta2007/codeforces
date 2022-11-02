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

double bin[1010][1010];
int in[1010];
vector<int> pl[1010];
inline int cmp(int x,int y){return x>y;}
int cnt[1010];
bool hasst[1010];
double pp[1010][1010];
int main(){
    bin[0][0]=1;
    REP1(i,1,1000){
        bin[i][0]=bin[i][i]=1;
        REP1(j,1,i-1){
            bin[i][j]=bin[i-1][j]+bin[i-1][j-1];
        }
    }
    int n,m;
    RII(n,m);
    int c=0;
    REP(i,m){
        int k;
        RI(k);
        REP(j,k){
            DRI(a);
            pl[i].PB(a);
            in[c++]=a;
        }
    }
    sort(in,in+c,cmp);
    int st=in[n-1];
    int cl=0,cst=0;
    REP(i,m){
        cnt[i]=0;
        REP(j,pl[i].size()){
            if(pl[i][j]>st){
                cnt[i]++;
                cl++;
            }else if(pl[i][j]==st){
                hasst[i]=1;
//                cst++;
            }
        }
    }
    pp[0][0]=1;
    REP(i,m){
        if(!hasst[i]){
            REP1(j,0,cst){
                pp[i+1][j]=pp[i][j];
            }
        }else{
            double fac=(cnt[i]+1.0)/(pl[i].size()-cnt[i]);
            REP1(j,0,cst){
                pp[i+1][j]+=pp[i][j]*(1.0-j/(cst+1.0));
                pp[i+1][j+1]+=pp[i][j]*((j+1)/(cst+1.0))*fac;
            }
            cst++;
        }
    }
    double base=1;
    REP(i,m)base*=bin[pl[i].size()][cnt[i]];
    printf("%.9lf\n",pp[m][n-cl]/base);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
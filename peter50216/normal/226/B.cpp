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

int in[101000];
long long sum[101000];
bool cmp(int a,int b){return a>b;}
int main(){
    DRI(n);
    REP(i,n)RI(in[i]);
    sort(in,in+n,cmp);
    DRI(q);
    sum[0]=0;
    REP(i,n)sum[i+1]=sum[i]+in[i];
    long long a1=0;
    REP1(i,1,n-1)a1+=i*1LL*in[i];
    while(q--){
        DRI(k);
        if(k==1)printf("%I64d",a1);
        else{
            int np=1;
            long long s=k,ans=0;
            int cnt=1;
            while(np<n){
                long long tnp=np+s;
                if(tnp>n)tnp=n;
                ans+=cnt*(sum[tnp]-sum[np]);
                np=tnp;
                s*=k;
                cnt++;
            }
            printf("%I64d",ans);
        }
        printf("%c",SEP(!q));
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
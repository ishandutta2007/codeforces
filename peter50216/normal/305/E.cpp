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

char in[5050];
int pc[5050],pp[5050];
int allc[5050];
int nn[5050];
int vis[5050],visid;
inline int nim(int a){
    return nn[a];
}
int main(){
    nn[0]=0;
    nn[1]=1;
    nn[2]=1;
    REP1(a,3,5000){
        visid++;
        vis[nn[a-2]]=visid;
        vis[nn[a-3]]=visid;
        REP1(i,1,a){
            if(a-3-i<i)break;
            vis[nn[a-3-i]^nn[i]]=visid;
        }
        while(vis[nn[a]]==visid)nn[a]++;
    }
    RS(in);
    int n=strlen(in);
    int ans=0;
    int cnt=0,cc=0;
    REP1(i,1,n-1){
        if(i<n-1&&in[i-1]==in[i+1]){
            cnt++;
            pc[i]=cc;
            pp[i]=cnt;
        }else{
            ans^=nim(cnt);
            allc[cc++]=cnt;
            cnt=0;
        }
    }
    puts(ans?"First":"Second");
    if(ans){
        REP1(i,1,n-2){
            if(in[i-1]==in[i+1]){
                int aa=ans^nim(allc[pc[i]]);
                if(pp[i]>2)aa^=nim(pp[i]-2);
                if(pp[i]<=allc[pc[i]]-2)aa^=nim(allc[pc[i]]-1-pp[i]);
                if(aa==0){
                    PI(i+1);
                    return 0;
                }
            }
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
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

int n;
vector<int> ed[80100];
inline ULL sq(ULL a){
    return a*a;
}
ULL t1[80100],t2[80100],t3[80100],t4[80100];
inline ULL s2(vector<int>& a){
    t1[0]=t2[0]=t3[0]=t4[0]=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        ULL ai=a[i];
        t1[i+1]=t1[i]+ai;
        t2[i+1]=t2[i]+ai*t1[i];
        t3[i+1]=t3[i]+ai*t2[i];
        t4[i+1]=t4[i]+ai*t3[i];
    }
    return t2[n]*2+t3[n]*6+t4[n]*6;
}
inline ULL solve(int np,int p,ULL& cr){
//    printf("
    vector<int> cs;
    ULL ret=0;
    for(int i=0;i<ed[np].size();i++){
        int y=ed[np][i];
        if(y==p)continue;
        ULL cc;
        ULL r=solve(y,np,cc);
        ret+=r;
        cs.PB(cc);
    }
    ULL ss=0;
    ULL s4=0;
    ULL s=0;
    for(int i=0;i<cs.size();i++){
        ss+=sq(cs[i]);
        s+=cs[i];
        s4+=sq(sq(cs[i]));
    }
    //ret+=(sq(ss)-s4)/2*2;
    ret+=(sq(ss)-s4)/2;
    for(int i=0;i<cs.size();i++){
        ULL rs=n-1-cs[i];
        ULL las=n-s-1;
        ULL rss=ss-sq(cs[i])+sq(las);
        ULL st=s-cs[i]+las;
        ULL c=cs[i];
        ret+=c*(c-1)*(rs+(sq(st)-rss)/2)*2;
        ret+=c*(c-1);
        ret+=2*c*(rs+(sq(st)-rss)/2);
        ret+=c;
    }
    cs.push_back(n-1-s);
    ret+=s2(cs);
    cr=1+s;
    //printf("solve np=%d p=%d %I64u\n",np,p,ret);
    return ret;
}
int main(){
    RI(n);
    REP(i,n-1){
        DRII(a,b);
        a--;b--;
        ed[a].PB(b);
        ed[b].PB(a);
    }
    ULL ans=sq(n*(n-1ULL)/2);
    ULL c;
    printf("%I64u\n",ans-solve(0,-1,c));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
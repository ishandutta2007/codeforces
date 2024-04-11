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
int n,m;
int ai[101000];
set<PII> ds[17];
LL ss[17];
inline void ins(int k,int x){
  //printf("ins k=%d x=%d\n",k,x);
  PII t=MP(x,x);
  set<PII>::iterator it=ds[k].lower_bound(t);
  int d1=0,d2=0;
  if(it!=ds[k].begin()){
    set<PII>::iterator it2=it;
    it2--;
    if(it2->S==x-1){
      d1=it2->S-it2->F+1;
      ds[k].erase(it2);
    }
  }
  if(it!=ds[k].end()){
    if(it->F==x+1){
      d2=it->S-it->F+1;
      ds[k].erase(it);
    }
  }
  ss[k]+=(d1+1LL)*(d2+1LL);
  //printf("insert %d %d\n",x-d1,x+d2);
  ds[k].insert(MP(x-d1,x+d2));
}

inline void del(int k,int x){
  //printf("del k=%d x=%d\n",k,x);
  PII t=MP(x,n+1);
  set<PII>::iterator it=ds[k].lower_bound(t);
  it--;
  //printf("%d %d\n",it->F,it->S);
  ds[k].erase(it);
  PII v1=MP(it->F,x-1);
  PII v2=MP(x+1,it->S);
  ss[k]-=(v1.S-v1.F+2LL)*(v2.S-v2.F+2LL);
  if(v1.F<=v1.S)ds[k].insert(v1);
  if(v2.F<=v2.S)ds[k].insert(v2);
}
int main(){
  RII(n,m);
  REP(i,n){
    DRI(a);
    REP(j,17){
      if(a&(1<<j))ins(j,i);
    }
    ai[i]=a;
  }
  while(m--){
    DRII(x,y);
    x--;
    LL ans=0;
    REP(j,17){
      if((ai[x]&(1<<j))!=(y&(1<<j))){
        if(ai[x]&(1<<j))del(j,x);
        else ins(j,x);
      }
      //printf("ss[%d]=%d\n",j,(int)ss[j]);
      ans+=ss[j]*(1LL<<j);
    }
    ai[x]=y;
    printf("%I64d\n",ans);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
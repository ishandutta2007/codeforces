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

int a[1010000];
int u[1010000];
inline bool cmp(int x,int y){return a[x]>a[y];}
bool XD[1010000];
int p[1010000];
int mi[5310000];
int cnt[5310000];
const int INF = 1000000000;
inline void up(int np){
  mi[np]=min(mi[np*2],mi[np*2+1]);
  cnt[np]=cnt[np*2]+cnt[np*2+1];
}
inline void ins(int np,int l,int r,int x,int c){
  if(l==r){
    mi[np]=c;
    cnt[np]=(c==INF);
    return;
  }
  int m=(l+r)/2;
  if(x<=m)ins(np*2,l,m,x,c);
  else ins(np*2+1,m+1,r,x,c);
  up(np);
}
inline int cc(int np,int l,int r,int x,int y){
  if(l==x&&r==y)return cnt[np];
  int m=(l+r)/2;
  if(x<=m&&y>m)return cc(np*2,l,m,x,m)+cc(np*2+1,m+1,r,m+1,y);
  else if(x>m)return cc(np*2+1,m+1,r,x,y);
  else return cc(np*2,l,m,x,y);
}
inline int flul(int np,int l,int r,int x,int c){
  //printf("frul %d %d %d %d %d %d\n",np,l,r,x,c,mi[np]);
  if(r==x){
    if(mi[np]>=c)return l;
  }
  if(l==r){
    return r+1;
  }
  int m=(l+r)/2;
  if(x<=m)return flul(np*2,l,m,x,c);
  else{
    int ll=flul(np*2+1,m+1,r,x,c);
    if(ll>m+1)return ll;
    return flul(np*2,l,m,m,c);
  }
}
inline int frul(int np,int l,int r,int x,int c){
  //printf("frul %d %d %d %d %d %d\n",np,l,r,x,c,mi[np]);
  if(l==x){
    if(mi[np]>=c)return r;
  }
  if(l==r){
    return l-1;
  }
  int m=(l+r)/2;
  if(x>m)return frul(np*2+1,m+1,r,x,c);
  else{
    int rr=frul(np*2,l,m,x,c);
    if(rr<m)return rr;
    return frul(np*2+1,m+1,r,m+1,c);
  }
}
int main(){
  DRII(n,k);
  REP(i,n){RI(a[i]);a[i]--;}
  REP(i,k){
    DRI(x);
    x--;
    XD[x]=1;
  }
  REP(i,n){
    p[a[i]]=i;
    if(XD[a[i]])u[i]=1;
  }
  REP(i,n)ins(1,0,n-1,i,a[i]);
  LL ans=0;
  REP(ii,n){
    int i=p[ii];
    if(u[i])continue;
   // printf("i=%d ii=%d\n",i,ii);
    int l=flul(1,0,n-1,i,a[i]);
    int r=frul(1,0,n-1,i,a[i]);
    //printf("r=%d\n",r);
    ans+=r-l+1-cc(1,0,n-1,l,r);
    ins(1,0,n-1,i,INF);
  }
  printf("%I64d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
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

int mod=1000000007;

int fac[200100];
int rfac[200100];

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
inline int mul(int a,int b){return (a*(LL)b)%mod;}
inline int bin(int a,int b){
  if(b<0||b>a)return 0;
  int ret=mul(fac[a],mul(rfac[b],rfac[a-b]));
  return ret;
}

bool np[101000];
int pr[101000],pc;
int ff[101000];
int lp[101000];

inline void init(){
  fac[0]=rfac[0]=1;
  fac[1]=1;
  REP1(i,2,200010){
    fac[i]=mul(fac[i-1],i);
  }
  rfac[1]=1;
  REP1(i,2,200010){
    rfac[i]=mul(rfac[mod%i],mod-mod/i);
  }
  REP1(i,2,200010){
    rfac[i]=mul(rfac[i],rfac[i-1]);
  }
  for(LL i=2;i<=100000;i++)if(!np[i]){
    pr[pc++]=i;
    for(LL j=i;j<=100000;j+=i){
      np[j]=1;
      lp[j]=i;
    }
  }
  ff[1]=1;
  REP1(i,2,100000){
    int p=lp[i];
    if(i%(p*(LL)p)==0)ff[i]=0;
    else ff[i]=-ff[i/p];
  }
}
int main(){
  init();
  CASET{
    DRII(n,f);
    int ans=0;
    for(int i=1;i*i<=n;i++){
      if(n%i==0){
        if(ff[i]==1)ans=add(ans,bin(n/i-1,f-1));
        else if(ff[i]==-1)ans=sub(ans,bin(n/i-1,f-1));
        if(n!=i*i){
          int j=n/i;
          if(ff[j]==1)ans=add(ans,bin(n/j-1,f-1));
          else if(ff[j]==-1)ans=sub(ans,bin(n/j-1,f-1));
        }
      }
    }
    printf("%d\n",ans);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
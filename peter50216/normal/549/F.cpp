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

int ai[301000];

int l[301000],r[301000];
int id[301000];

int ps[301000];

int n,k;
inline int add(int a,int b){
  a+=b;
  if(a>=k)a-=k;
  return a;
}
inline int sub(int a,int b){
  a-=b;
  if(a<0)a+=k;
  return a;
}
vector<int> psid[1000100];
inline bool cmp(int a,int b){
  return ai[a]<ai[b];
}

bool used[301000];
inline int query(int x,int y,int v){
  return upper_bound(psid[v].begin(),psid[v].end(),y)-lower_bound(psid[v].begin(),psid[v].end(),x);
}
inline LL solve(int x1,int y1,int x2,int y2,int v){
  LL ret=0;
  if(y1-x1>y2-x2){
    REP1(i,x2,y2){
      ret+=query(x1-1,y1-1,sub(ps[i],v));
    }
  }else{
    REP1(i,x1-1,y1-1){
      ret+=query(x2,y2,add(ps[i],v));
    }
  }
  return ret;
}

int main(){
  RII(n,k);
  REP1(i,1,n)RI(ai[i]);
  ps[0]=0;
  REP1(i,1,n)ps[i]=add(ps[i-1],ai[i]%k);
  REP1(i,0,n)psid[ps[i]].push_back(i);
  REP1(i,1,n){
    l[i]=r[i]=id[i-1]=i;
  }
  sort(id,id+n,cmp);
  LL ans=0;
  REP(ii,n){
    int i=id[ii];
    used[i]=1;
    if(i>1&&used[i-1]){
      ans+=solve(l[i-1],i-1,i,i,ai[i]%k);
      l[i]=l[i-1];
      r[l[i-1]]=i;
    }
    if(i<n&&used[i+1]){
      ans+=solve(l[i],i,i+1,r[i+1],ai[i]%k);
      r[l[i]]=r[i+1];
      l[r[i+1]]=l[i];
    }
  }
  printf("%I64d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
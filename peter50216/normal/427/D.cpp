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

char a[5100], b[5100];
// Suffix array by Induced-Sorting, O(n)
const int MAXL=11000+1000; // Max Length
// input: S[0..n-1], n; output: SA[0..n-1]
// S[n-1] MUST be an unique smallest item!!!!
// Max alphabet should be < MAXL.
int S[MAXL*2],SA[MAXL*2];

bool _iss[MAXL*2];
int _p[MAXL*2],_pb[MAXL*2],cnt[MAXL],qe[MAXL];
inline void isort(int n,int *s,int *sa,bool *iss,int *p,int pc){
    int a=0,i;
    for(i=0;i<n;i++)a=max(a,s[i]); a++;
    memset(cnt,0,sizeof(int)*a);
    for(i=0;i<n;i++)cnt[s[i]]++;
    qe[0]=cnt[0]; for(i=1;i<a;i++)qe[i]=qe[i-1]+cnt[i];
    memset(sa,-1,sizeof(int)*n);
    for(i=pc-1;i>=0;i--)sa[--qe[s[p[i]]]]=p[i];
    qe[0]=0; for(i=1;i<a;i++)qe[i]=qe[i-1]+cnt[i-1];
    for(i=0;i<n;i++)if(sa[i]>0&&!iss[sa[i]-1])sa[qe[s[sa[i]-1]]++]=sa[i]-1;
    qe[0]=cnt[0]; for(i=1;i<a;i++)qe[i]=qe[i-1]+cnt[i];
    for(i=n-1;i>=0;i--)if(sa[i]>0&&iss[sa[i]-1])sa[--qe[s[sa[i]-1]]]=sa[i]-1;
}
inline bool eq(int *s,bool *iss,int *pp,int *pb,int pc,int x,int p){
    if(pb[p]==pc-1 || pb[x]==pc-1 || pp[pb[p]+1]-p!=pp[pb[x]+1]-x)return 0;
    for(int j=0;j<=pp[pb[p]+1]-p;j++)if(s[j+p]!=s[j+x]||iss[j+p]!=iss[j+x]) return 0;
    return 1;
}
void suffixArray(int n,int a1=0){
    int i;
    int *s=S+a1,*sa=SA+a1,*pp=_p+a1,*pb=_pb+a1;
    bool *iss=_iss+a1;
    iss[n-1]=1;
    for(i=n-2;i>=0;i--)iss[i]=s[i]<s[i+1]||(s[i]==s[i+1]&&iss[i+1]);
    int pc=0;
    for(i=1;i<n;i++)if(iss[i]&&!iss[i-1]){ pp[pc]=i; pb[i]=pc; pc++; }
    isort(n,s,sa,iss,pp,pc);
    int p=-1,c=-1;
    for(i=0;i<n;i++){
        int x=sa[i];
        if(x&&iss[x]&&!iss[x-1]){
            if(p==-1||!eq(s,iss,pp,pb,pc,x,p))c++;
            s[n+pb[x]]=c;
            p=x;
        }
    }
    if(c==pc-1)for(i=0;i<pc;i++)sa[n+s[n+i]]=i;
    else suffixArray(pc,a1+n);
    for(i=0;i<pc;i++)pb[i]=pp[sa[n+i]];
    isort(n,s,sa,iss,pb,pc);
}
int rk[MAXL],DA[MAXL];
void depthArray(int n){
    int i,j;
    for(i=0;i<n;i++) rk[SA[i]]=i;
    for(i=j=0;i<n;i++){
        if(!rk[i]){ j=0; }
        else{
            if(j) j--;
            for(;S[i+j]==S[SA[rk[i]-1]+j];j++);
        }
        DA[rk[i]]=j;
    }
}

int main(){
  RS(a);RS(b);
  int al=strlen(a),bl=strlen(b);
  REP(i,al)S[i]=a[i];
  S[al]=1;
  REP(i,bl)S[i+al+1]=b[i];
  S[al+bl+1]=0;
  int n=al+bl+2;
  suffixArray(n);
  depthArray(n);
  int ans=1000000000;
  REP1(i,1,n-1){
    int i1=SA[i-1],i2=SA[i];
    if((i1<al&&i2>al&&i2<al+bl+1)||(i2<al&&i1>al&&i1<al+bl+1)){
      int mi=0;
      if(i>1){
        if(DA[i-1]>=DA[i])continue;
        mi=max(mi,DA[i-1]+1);
      }
      if(i<n-1){
        if(DA[i+1]>=DA[i])continue;
        mi=max(mi,DA[i+1]+1);
      }
      ans=min(ans,mi);
    }
  }
  if(ans==1000000000)ans=-1;
  PI(ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
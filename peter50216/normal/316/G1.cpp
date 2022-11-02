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
// Suffix array by Induced-Sorting, O(n)
const int MAXL=560000+1000; // Max Length
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
int tn;
char s[50100];
int n;
char r[12][50100];
int ai[12],bi[12];
int li[12];
int ss[12],se[12];
short rmqt[20][MAXL];
int log2v[MAXL];
inline void build_rmqt(){
    REP(i,tn){
        rmqt[0][i]=DA[i];
    }
    for(int j=1;(1<<j)<=tn;j++){
        for(int i=0;i+(1<<j)<=tn;i++){
            rmqt[j][i]=min(rmqt[j-1][i],rmqt[j-1][i+(1<<(j-1))]);
        }
    }
    log2v[1]=0;
    for(int i=2;i<MAXL;i++)log2v[i]=log2v[i/2]+1;
}
const int INF=1000000000;
inline int rmq(int a,int b){
    if(a>b)return INF;
    int k=log2v[b-a+1];
    return min(rmqt[k][a],rmqt[k][b-(1<<k)+1]);
}
int psum[MAXL][12];
inline int getmaxl(int x,int len){
    int l=x,r=tn-1;
    while(l<r){
        int m=(l+r+1)/2;
        if(rmq(x+1,m)>=len)l=m;
        else r=m-1;
    }
    return l;
}
inline int getminl(int x,int len){
    int l=0,r=x;
    while(l<r){
        int m=(l+r)/2;
        if(rmq(m+1,x)>=len)r=m;
        else l=m+1;
    }
    return l;
}
int main(){
    RS(s);
    RI(n);
    REP(i,n){
        RS(r[i]);
        RII(ai[i],bi[i]);
        li[i]=strlen(r[i]);
    }
    tn=0;
    int l=strlen(s);
    REP(i,n){
        ss[i]=tn;
        REP(j,li[i]){
            S[tn++]=r[i][j];
        }
        se[i]=tn;
        S[tn++]='z'+i+1;
    }
    ss[n]=tn;
    REP(i,l){
        S[tn++]=s[i];
    }
    se[n]=tn;
    S[tn++]=0;
    suffixArray(tn);
    depthArray(tn);
    build_rmqt();
    /*REP(i,tn){
        printf("#%d %d %d: ",i,SA[i],DA[i]);
        REP1(j,SA[i],tn-1){
            if(S[j]==0)printf("%d",S[j]);
            else if(S[j]>'z')printf("%d",S[j]-'z');
            else printf("%c",S[j]);
        }
        puts("");
    }*/
    REP(i,tn){
        REP(j,n){
            psum[i+1][j]=psum[i][j];
            if(SA[i]>=ss[j]&&SA[i]<=se[j])psum[i+1][j]++;
        }
    }
    int lst=-1,ans=0;
    REP(i,tn){
        if(!(SA[i]>=ss[n]&&SA[i]<=se[n]))continue;
        int len=tn-SA[i]-1;
        if(len==0)continue;
        int l,r=len;
        if(lst==-1)l=1;
        else l=rmq(lst+1,i)+1;
        if(l<=r){
            int ll,rr;
            int minl=-1,maxl=-1;
            {
                ll=l;rr=r;
                while(ll<rr){
                    int m=(ll+rr+1)/2;
                    int lef=getminl(i,m);
                    int rig=getmaxl(i,m);
                    bool f=1;
                    REP(j,n){
                        int cc=psum[rig+1][j]-psum[lef][j];
                        if(cc<ai[j]){
                            f=0;break;
                        }
                    }
                    if(f)ll=m;
                    else rr=m-1;
                }
                int lef=getminl(i,ll);
                int rig=getmaxl(i,ll);
                bool f=1;
                REP(j,n){
                    int cc=psum[rig+1][j]-psum[lef][j];
                    if(cc<ai[j]){
                        f=0;break;
                    }
                }
                if(f)maxl=ll;
            }
            {
                ll=l;rr=r;
                while(ll<rr){
                    int m=(ll+rr)/2;
                    int lef=getminl(i,m);
                    int rig=getmaxl(i,m);
                    bool f=1;
                    REP(j,n){
                        int cc=psum[rig+1][j]-psum[lef][j];
                        if(cc>bi[j]){
                            f=0;break;
                        }
                    }
                    if(f)rr=m;
                    else ll=m+1;
                }
                int lef=getminl(i,ll);
                int rig=getmaxl(i,ll);
                bool f=1;
                REP(j,n){
                    int cc=psum[rig+1][j]-psum[lef][j];
                    if(cc>bi[j]){
                        f=0;break;
                    }
                }
                if(f)minl=ll;
            }
            //printf("i=%d l=%d r=%d %d %d\n",i,l,r,minl,maxl);
            if(minl!=-1&&maxl!=-1&&maxl>=minl)ans+=maxl-minl+1;
        }
        lst=i;
    }
    PI(ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
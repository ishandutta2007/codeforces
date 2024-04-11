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

int xi[101000];

inline bool cmp(int a,int b){return xi[a]<xi[b];}
set<int> all;
map<int,int> toid;
int n;
LL sum[101000];
LL s2[101000];
int id[101000];
LL cov[2][801000],sumt[2][801000];
inline void down(int k,int np,int l,int r){
    int m=(l+r)/2;
    if(cov[k][np]){
        cov[k][np]=0;
        cov[k][np*2]=cov[k][np*2+1]=1;
        sumt[k][np*2]=sumt[k][np*2+1]=0;
    }
    sumt[k][np*2]+=sumt[k][np];
    sumt[k][np*2+1]+=sumt[k][np];
    sumt[k][np]=0;
}
inline LL que(int k,int np,int l,int r,int x){
    if(l==r)return sumt[k][np];
    down(k,np,l,r);
    int m=(l+r)/2;
    if(x<=m)return que(k,np*2,l,m,x);
    else return que(k,np*2+1,m+1,r,x);
}
inline void cover(int k,int np,int l,int r,int x,int y){
    if(l==x&&r==y){
        cov[k][np]=1;
        sumt[k][np]=0;
        return;
    }
    down(k,np,l,r);
    int m=(l+r)/2;
    if(x<=m&&y>m){cover(k,np*2,l,m,x,m);cover(k,np*2+1,m+1,r,m+1,y);}
    else if(y<=m)cover(k,np*2,l,m,x,y);
    else cover(k,np*2+1,m+1,r,x,y);
}
inline void add(int k,int np,int l,int r,int x,int y,LL c){
    if(l==x&&r==y){
        sumt[k][np]+=c;
        return;
    }
    down(k,np,l,r);
    int m=(l+r)/2;
    if(x<=m&&y>m){add(k,np*2,l,m,x,m,c);add(k,np*2+1,m+1,r,m+1,y,c);}
    else if(y<=m)add(k,np*2,l,m,x,y,c);
    else add(k,np*2+1,m+1,r,x,y,c);
}
inline LL sq(int x){
    return que(0,1,1,n,x)+sum[x];
}
inline LL sqs(int x){
    return que(1,1,1,n,x)+s2[x];
}
int ord[101000];
inline LL solve(int l,int r){
    set<int>::iterator it1,it2;
    it1=all.lower_bound(l);
    if(it1==all.end())return 0;
    it2=all.upper_bound(r);
    if(it2==all.begin())return 0;
    it2--;
    l=ord[toid[*it1]];
    r=ord[toid[*it2]];
    if(l>r)return 0;
    LL ret=0;
  //  printf("  l=%d r=%d %d %d %I64d %I64d\n",l,r,*it1,*it2,sq(l-1),sq(r));
    ret-=(r+l)*(sq(r)-sq(l-1));
    ret+=2*(sqs(r)-sqs(l-1));
    return ret;
}
int main(){
    RI(n);
    REP1(i,1,n){
        RI(xi[i]);
        id[i]=i;
        all.insert(xi[i]);
        toid[xi[i]]=i;
        //printf("xi[%d]=%d\n",i,xi[i]);
    }
    sort(id+1,id+n+1,cmp);
    REP1(i,1,n){
        ord[id[i]]=i;
        sum[i]=sum[i-1]+xi[id[i]];
        s2[i]=s2[i-1]+xi[id[i]]*(LL)i;
    }
    DRI(m);
    while(m--){
        DRI(t);
        if(t==1){
            DRII(p,d);
            if(d==0)continue;
            if(d>0){
                int t=ord[p];
                while(t<=n&&xi[id[t]]<xi[p]+d)t++;
                t--;
                xi[p]+=d;
                int pp=ord[p];
                for(int i=pp;i<t;i++)id[i]=id[i+1];
                id[t]=p;
                for(int i=pp;i<=t;i++)ord[id[i]]=i;
                LL t1=sq(t);
                LL t2=sqs(t);
                sum[pp]=sq(pp-1)+xi[id[pp]];
                s2[pp]=sqs(pp-1)+xi[id[pp]]*(LL)pp;
                for(int i=pp+1;i<=t;i++){
                    sum[i]=sum[i-1]+xi[id[i]];
                    s2[i]=s2[i-1]+xi[id[i]]*(LL)i;
                }
                cover(0,1,1,n,pp,t);
                cover(1,1,1,n,pp,t);
                if(t<n){
                    add(0,1,1,n,t+1,n,sum[t]-t1);
                    add(1,1,1,n,t+1,n,s2[t]-t2);
                }
            }else{
                int t=ord[p];
                while(t>=1&&xi[id[t]]>xi[p]+d)t--;
                t++;
                xi[p]+=d;
                int pp=ord[p];
                for(int i=pp;i>t;i--)id[i]=id[i-1];
                id[t]=p;
                for(int i=t;i<=pp;i++)ord[id[i]]=i;
                LL t1=sq(pp);
                LL t2=sqs(pp);
                sum[t]=sq(t-1)+xi[id[t]];
                s2[t]=sqs(t-1)+xi[id[t]]*(LL)t;
                for(int i=t+1;i<=pp;i++){
                    sum[i]=sum[i-1]+xi[id[i]];
                    s2[i]=s2[i-1]+xi[id[i]]*(LL)i;
                }
                cover(0,1,1,n,t,pp);
                cover(1,1,1,n,t,pp);
                if(pp<n){
                    add(0,1,1,n,pp+1,n,sum[pp]-t1);
                    add(1,1,1,n,pp+1,n,s2[pp]-t2);
                }
            }
            all.erase(xi[p]-d);
            all.insert(xi[p]);
            toid[xi[p]]=p;
            ////REP1(i,1,n)printf("%d ",xi[i]);puts("");
           // REP1(i,1,n)printf("%d ",ord[i]);puts("");
           // solve(50,872);
        }else{
            DRII(l,r);
          //  REP1(i,1,n)printf("%d ",xi[i]);puts("");
          //  REP1(i,1,n)printf("%d ",ord[i]);puts("");
            printf("%I64d\n",solve(l,r));
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
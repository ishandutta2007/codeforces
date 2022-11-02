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
int tid=0;
int allx[301000],xc=0;
int li[101000],ri[101000],ti[101000];
int lid[101000],rid[101000];
int ans[101000];
int que[101000];
struct XD{
    int t;
    int isin;
    int id;
    XD(int tt=0,int ii=0,int idd=0):t(tt),isin(ii),id(idd){}
    bool operator<(const XD& b)const{
        return t<b.t;
    }
}allv[201000],allq[301000];
int ma[201000];
int main(){
    DRII(m,n);
    REP(i,n){
        RIII(li[i],ri[i],ti[i]);
        allx[xc++]=li[i];
        allx[xc++]=ri[i];
    }
    sort(allx,allx+xc);
    xc=unique(allx,allx+xc)-allx;
    REP(i,n){
        lid[i]=lower_bound(allx,allx+xc,li[i])-allx;
        rid[i]=lower_bound(allx,allx+xc,ri[i])-allx;
    }
    REP(i,m)RI(que[i]);
    int vc=0;
    REP(i,n){
        allv[vc++]=XD(lid[i],1,i);
        allv[vc++]=XD(rid[i],0,i);
    }
    sort(allv,allv+vc);
    int i,j=0;
    set<pair<int,int> > evs;
    for(i=0;i<xc;i++){
        for(;j<vc&&allv[j].t==i;j++){
            if(allv[j].isin)evs.insert(MP(ti[allv[j].id],allv[j].id));
            else evs.erase(MP(ti[allv[j].id],allv[j].id));
        }
        if(evs.empty())ma[i]=-1;
        else ma[i]=(evs.begin())->F;
    }
    int qc=0;
    REP(i,xc-1){
        //printf("ma[%d]=%d\n",i,ma[i]);
        if(ma[i]>=0){
            allq[qc++]=XD(ma[i]-allx[i+1],1,i+1);
            allq[qc++]=XD(ma[i]-allx[i],0,i);
        }
    }
    REP(i,m){
        allq[qc++]=XD(que[i],2,i);
    }
    sort(allq,allq+qc);
    LL tot=0;
    int ts=0;
    REP(i,qc){
      //  printf("tot=%d ts=%d %d t=%d id=%d\n",(int)tot,ts,allq[i].isin,allq[i].t,allq[i].id);
        if(allq[i].isin==2){
            ans[allq[i].id]=tot+ts*(LL)allq[i].t;
        }else if(allq[i].isin==1){
            ts++;
            tot-=allq[i].t;
        }else{
            ts--;
            tot+=allq[i].t;
        }
    }
    REP(i,m)PI(ans[i]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
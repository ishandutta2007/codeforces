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

vector<PII> ed[101000];
int pre[101000];
LL dis[101000];
const LL INF = 1234567890123456LL;

int main(){
  DRII(n,m);
  REP(i,m){
    DRIII(a,b,w);
    a--;b--;
    ed[a].push_back({b,w});
    ed[b].push_back({a,w});
  }
  priority_queue<pair<LL,int>> pq;
  REP(i,n)dis[i]=INF;
  dis[0]=0;
  pq.push({0,0});
  while(!pq.empty()){
    int np;
    LL d;
    tie(d,np)=pq.top();
    d*=-1;
    pq.pop();
    if(d!=dis[np])continue;
    for(auto p:ed[np]){
      int y,l;
      tie(y,l)=p;
      if(dis[y]>d+l){
        dis[y]=d+l;
        pre[y]=np;
        pq.push({-dis[y],y});
      }
    }
  }
  if(dis[n-1]==INF)puts("-1");
  else{
    vector<int> v;
    int np=n-1;
    while(np){
      v.push_back(np);
      np=pre[np];
    }
    v.push_back(0);
    reverse(ALL(v));
    REP(i,SZ(v))printf("%d%c",v[i]+1,SEP(i==SZ(v)-1));
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
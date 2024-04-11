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
vector<int> ve,vo;
int n,k,p;
int ne,no;
vector<int> ae[101000],ao[101000];
inline bool solve(){
  if(vo.size()%2!=no%2)return false;
  if(vo.size()<no)return false;
  if((SZ(vo)-no)/2+SZ(ve)<ne)return false;
  puts("YES");
  REP(i,no){
    int v=vo.back();
    vo.pop_back();
    ao[i].push_back(v);
  }
  REP(i,ne){
    if(ve.size()){
      int v=ve.back();
      ve.pop_back();
      ae[i].push_back(v);
    }else{
      int v;
      v=vo.back();
      vo.pop_back();
      ae[i].push_back(v);
      v=vo.back();
      vo.pop_back();
      ae[i].push_back(v);
    }
  }
  if(ne){
    REP(i,SZ(vo))ae[0].push_back(vo[i]);
    REP(i,SZ(ve))ae[0].push_back(ve[i]);
  }else{
    REP(i,SZ(vo))ao[0].push_back(vo[i]);
    REP(i,SZ(ve))ao[0].push_back(ve[i]);
  }
  REP(i,ne){
    printf("%d",SZ(ae[i]));
    REP(j,SZ(ae[i]))printf(" %d",ae[i][j]);puts("");
  }
  REP(i,no){
    printf("%d",SZ(ao[i]));
    REP(j,SZ(ao[i]))printf(" %d",ao[i][j]);puts("");
  }
  return true;
}
int main(){
  RIII(n,k,p);
  REP(i,n){
    DRI(a);
    if(a%2)vo.push_back(a);
    else ve.push_back(a);
  }
  ne=p;no=k-ne;
  if(!solve())puts("NO");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ld,ld>pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)for(int i=(a);i<(b);i++)
#define REP(i,n)FOR(i,0,n)
#define SORT(v)sort((v).begin(),(v).end())
#define UN(v)SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)memset(a,b,sizeof a)
#define pb push_back

#define ignore ignore222

pii e[444444];
int CNT[444444];
int n,k;
int a[222222];
vi  v[222222];
int u[222222];
int now;
vi w[222222];
int c[222222];
int ignore[222222];
int nignore;

int ur[444444];
int r[444444];
int nr;

int getcnt(int edge){
  if(ur[edge]==nr)return r[edge];
  int res = 1;
  int ver = e[edge].second;
  REP(i,w[ver].size()){
    int e2 = w[ver][i];
    if((e2^1)==edge) continue;
    res += getcnt(e2);
  }
  return ur[edge] = nr,r[edge] = res;
}

int dfs3(int ver,int par,int total){
  int num = 1;
  REP(i,w[ver].size()){
    int e2 = w[ver][i];
    if(e[e2].second == par)continue;
    int t = dfs3(e[e2].second, ver, total);
    ur[e2]=nr;r[e2]=t;
    ur[e2^1]=nr;r[e2^1]=total-t;
    num += t;
  }
  return num;
}

vi z;
void dfs(int ver){
  if(u[ver]==now)return;
  u[ver]=now;
  z.pb(ver);
  REP(i,w[ver].size()) dfs(e[w[ver][i]].second);
}

pii bst;

void dfs2(int ver,int cnt,int par=-1){
  if(bst.second < cnt) bst = pii(ver,cnt);
  REP(i,w[ver].size()){
    int nw = e[w[ver][i]].second;
    if(nw==par || ignore[nw] == nignore) continue;
    dfs2(nw,cnt+c[nw],ver);
  }
}

pii farthest(int ver){
  bst=pii(0,0);
  dfs2(ver,c[ver]);
  //cout<<"ver: "<<ver<<" : " <<bst.first<<' '<<bst.second<<endl;
  return bst;
}

bool solve(int ver){
  now++;
  z.clear();
  dfs(ver);

  if(z.size() == n) return true;
  nignore++;
  dfs3(z[0],-1,z.size());
  REP(i,z.size()){
    int t = z[i];
    REP(j,w[t].size()){
      //cout<<w[t][j]<<' '<<CNT[w[t][j]]<<' '<<getcnt(w[t][j])<<endl;
      if (CNT[w[t][j]] == getcnt(w[t][j])){
	c[t] += CNT[w[t][j]];
	ignore[e[w[t][j]].second]=nignore;
      }
    }
  }
  int start=-1;
  REP(i,z.size())if(ignore[z[i]]!=nignore)start=z[i];
  //cout<<"!"<<start<<' '<<c[0]<<' '<<c[1]<<' '<<ignore[0]<<' '<<ignore[1]<<' '<<ignore[3]<<' '<<nignore<<endl;
  start = farthest(start).first;
  return farthest(start).second >= k;
}

bool good(int s){
  nr++;
  REP(i,n)w[i].clear();
  REP(i,n)REP(j,v[i].size())if(a[i]>=s && a[e[v[i][j]].second]>=s)w[i].pb(v[i][j]);
  REP(i,n)c[i]=1;
  int tt = now;
  REP(i,n)if(a[i]>=s&&u[i]<=tt){
    if(solve(i)) return true;
  } 
  return false;
}

bool DEBUG = 0;

int main(){
  cin>>n>>k;
  if(DEBUG)n=4,k=n/2;
  REP(i,n)scanf("%d",a+i);
  if(DEBUG)REP(i,n)a[i]=rand()%100+2,cout<<a[i]<<' ';if(DEBUG)puts("");
  REP(i,n-1){
    int x,y;
    scanf("%d %d",&x,&y);
    if(DEBUG)x=1,y=i+2;
    x--,y--;
    if(DEBUG)cout<<x<<' '<<y<<endl;
    e[2*i]=pii(x,y);
    e[2*i+1]=pii(y,x);
    v[x].pb(2*i);
    v[y].pb(2*i+1);
  }

  nr++;
  nignore=-1;
  REP(i,n)w[i]=v[i];
  dfs3(0,-1,n);
  REP(i,2*n-2){
    CNT[i]=getcnt(i);
  }
  nignore=2;
  int best = 0;
  int from = 0, to = 1000000;
  while(from<=to){
    int s= (from+to)/2;
    if(good(s)) best=s,from=s+1;
    else to=s-1;
  }
  cout<<best<<endl;
  return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

vi g[1024];int n;
set<int> w0,w1;
bool vis[1024];

void in(set<int>& w){
  w.clear();
  int k;
  scanf("%d",&k);
  while(k--){
    int x;
    scanf("%d",&x);x--;
    w.insert(x);
  }
}

bool dfs(int x, int t){
  vis[x]=1;
  if(x==t)return 1;
  for(int y:g[x])if(!vis[y]&&dfs(y,t))return 1;
  return 0;
}

int main(){
  int tn;
  scanf("%d",&tn);
  while(tn--){
    scanf("%d",&n);
    FORN(i,n)g[i].clear();
    FOR(_,1,n){
      int x,y;
      scanf("%d%d",&x,&y);x--;y--;
      g[x].push_back(y);g[y].push_back(x);
    }
    in(w0);in(w1);
    printf("B %d\n",(*w1.begin())+1);fflush(stdout);
    int x;
    scanf("%d",&x);x--;
    if(w0.count(x)){
      printf("C %d\n",x+1);fflush(stdout);
      continue;
    }
    memset(vis,0,sizeof(vis));
    for(int y:w0)vis[y]=1;
    bool found=0;
    for(int y:w0)if(dfs(y,x)){
      printf("A %d\n",y+1);fflush(stdout);
      int z;
      scanf("%d",&z);z--;
      if(w1.count(z))printf("C %d\n",y+1);
      else puts("C -1");
      fflush(stdout);
      found=1;
      break;
    }
    assert(found);
  }
  return 0;
}
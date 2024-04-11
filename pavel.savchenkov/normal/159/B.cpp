#include <cstdio>
#include <algorithm>
#include <memory.h>
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)

using namespace std;
int good[1100][1100];
int u = 0, v = 0;
int n,m;
int a[100500];
int b[100500];
bool used[100500];

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&m);
  memset(good,0,sizeof(good));
  memset(used,0,sizeof(used));
  
  forn(i,n) { int x,y; scanf("%d%d",&x,&y); good[x][y]++; }
  
  forn(i,m) 
  { 
    scanf("%d%d",&a[i],&b[i]);
    if (good[a[i]][b[i]] > 0) { v++; u++; good[a[i]][b[i]]--; used[i] = 1; }
  }
  
  forn(i,m)
  {
    if (used[i]) continue;
    foran(j,1,1001) if (good[j][b[i]] > 0) { good[j][b[i]]--; u++; break; } 
  }
  
  printf("%d %d\n",u,v);
  
  return 0;
}
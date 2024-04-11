#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

char s[10][10];
char bs[10][10];

int ans;

int start = clock();

const int dx[4][5] = {{0,1,2,1,1},{0,1,2,2,2},{1,1,0,1,2},{0,0,1,2,0}};
const int dy[4][5] = {{0,0,0,1,2},{1,1,0,1,2},{0,1,2,2,2},{0,1,1,1,2}};
int n,m;

bool q,q1;

void dfs(int x,int y,int cur){
    if (cur == ans){
      memcpy(bs,s,sizeof(bs));
      q = q1 = true;
      return;
    }
    if (x >= n-2){
        if (clock() - start > 2.7*CLOCKS_PER_SEC)
           q = true, q1 = false; 
        return;
    }
    if (y >= m-2){
        dfs(x+1,0,cur);
        return;
    }
    if (((m-y+1)+(n-x)*m)/5 + cur <= ans)
        return;
    if ((m-y-1)+(n-x-2)*m+cur <= ans)
        return;
    for (int i = 0; i < 4; i++){
        bool ok = !q;
        for (int j = 0; j < 5; j++)
            ok &= s[x+dx[i][j]][y+dy[i][j]] == 0;
        if (ok){
            for (int j = 0; j < 5; j++)
                s[x+dx[i][j]][y+dy[i][j]] = 'A'+cur;
            dfs(x,y+1,cur+1);
            for (int j = 0; j < 5; j++)
                s[x+dx[i][j]][y+dy[i][j]] = 0;
        }
    }
    if (!q)
        dfs(x,y+1,cur);
}


int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d",&n,&m);
  if (n > 2 && m > 2){
      for (ans = 0; ; ans++){
        cerr << ans << endl;
        q = q1= false;
        dfs(0,0,0);
        if (!q1){
            ans--;
            break;
        }
      }
  }
  printf("%d\n",ans);
  for (int i = 0; i < n; i++,printf("\n"))
    for (int j = 0; j < m; j++)
        if (bs[i][j] == 0)
            printf(".");
        else
            printf("%c",bs[i][j]); 
  return 0;
}
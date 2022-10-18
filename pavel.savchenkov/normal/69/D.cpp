#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#define i64 long long
#define pb push_back
using namespace std;
int x,y,n,d;
bool dp[500][500][2][2];
bool was[500][500][2][2];
int dx[50];
int dy[50];

bool dfs(int x,int y,bool inv1,bool inv2)
{
 if (x*x + y*y > d) return 1;
 if (was[x+200][y+200][inv1][inv2]) return dp[x+200][y+200][inv1][inv2];
 was[x+200][y+200][inv1][inv2] = 1;
 
 for (int i=0;i<n;i++)
  if (!dfs(x+dx[i],y+dy[i],inv2,inv1)) return dp[x+200][y+200][inv1][inv2] = 1;
  
 if (!inv1)
  if (!dfs(y,x,inv2,1)) return dp[x+200][y+200][0][inv2] = 1;

 return dp[x+200][y+200][inv1][inv2] = 0;
}

int main()
{
    cin >> x >> y >> n >> d;
    d *= d;
    for (int i=0;i<n;i++) cin >> dx[i] >> dy[i];
    memset(was,false,sizeof(was));
    if (dfs(x,y,0,0)) cout << "Anton" << endl; else cout << "Dasha" << endl;;
    return 0;
}
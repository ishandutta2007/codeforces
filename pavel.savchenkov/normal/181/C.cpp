#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
int a[20][200];
int b[20][200];
int c[20][200];
int n,m,k;
char str[20];
int d[110][110];

int solve(int from,int to)
{
    int res = 0;
    memset(d,0,sizeof(d));
    d[0][0] = 0;
    for (int j=0; j<=m; j++)
        for (int K=0; K<=k; K++)
        {
            res = max(res,d[j][K]);
            for (int next=0; next<=min(c[from][j],k-K); next++)
                d[j + 1][K + next] = max(d[j + 1][K + next], d[j][K] + (b[to][j] - a[from][j]) * next);
        }
    return res;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m >> k; scanf("\n");
  forn(i,n)
  {
    gets(str);
    forn(j,m)
        scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
    scanf("\n");
  }
  
  int ans = 0;
  
  forn(i,n)
    forn(j,n)
        if (i != j) ans = max(ans,solve(i,j));
        
  cout << ans << endl;
  return 0;
}
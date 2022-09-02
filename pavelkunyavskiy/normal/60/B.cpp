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

typedef long long int64;
typedef long double ld;

const int dx[6]={1,-1,0,0,0,0};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};

char c[15][15][15];
bool used[15][15][15];
int ans;
int k,n,m;

void dfs(int x,int y,int z){
    if (x<0 || x>=k)
        return;
    if (y<0 || y>=n) 
        return;
    if (z<0 || z>=m)
        return;
    if (c[x][y][z]!='.')
        return;
    if (used[x][y][z])
        return;
    used[x][y][z]=true;
    ++ans;
    for (int i=0;i<6;i++)
        dfs(x+dx[i],y+dy[i],z+dz[i]);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d %d",&k,&n,&m);
    for (int i=0;i<k;i++)
        for (int j=0;j<n;j++)
            for (int l=0;l<m;l++)
                scanf(" %c ",&c[i][j][l]);
    int x,y;
    scanf("%d %d",&x,&y);
    dfs(0,x-1,y-1);
    cout<<ans<<endl;    
    return 0;
}
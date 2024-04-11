#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#define ff first
#define ss second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef queue<int> qi;
typedef queue<ll> qll;
char b[2][100001];
int dp[2][100001];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,2)scanf("%s",b[i]);
    memset(dp,-1,sizeof(dp));
    queue<pii> q;
    dp[0][0]=0;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
                     int x=q.front().ff;
                     int y=q.front().ss;
                     q.pop();
                     if(y<dp[x][y])continue;
                     if(y+k>=n){puts("YES");return 0;}
                     if(b[x][y+1]=='-'&&dp[x][y+1]==-1){dp[x][y+1]=dp[x][y]+1;q.push(make_pair(x,y+1));}
                     if(y>0&&b[x][y-1]=='-'&&dp[x][y-1]==-1){dp[x][y-1]=dp[x][y]+1;q.push(make_pair(x,y-1));}
                     if(b[!x][y+k]=='-'&&dp[!x][y+k]==-1){dp[!x][y+k]=dp[x][y]+1;q.push(make_pair(!x,y+k));}
    }
    puts("NO");
    return 0;
}
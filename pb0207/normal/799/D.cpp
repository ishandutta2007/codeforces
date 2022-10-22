#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
const int MAX=2e5+5;
const int INF=1e9+5;
const double M=4e18;
using namespace std;
const int MOD=1e9+7;
typedef pair<int,int> pii;
const double eps=0.000000001;
ll n, a, b, h, w;
int len[1000005];
int dp[40][MAX];
bool cmp(int a,int b)
{
return a>b;
}
int solve(int i,ll h,ll w)
{
    if((h>=a&&w>=b)||(h>=b&&w>=a))
        return 0;
if(i==n+1)
return INF;
    if(h> 200000 )
        h= 200000 ;
    if(w> 200000 )
        w= 200000 ;
    int &re=dp[i][h];
    if(re+1)
        return re;
    int re1=INF,re2=INF;
    if(h<a&&len[i]>1)
        re1=1+solve(i+1,h*len[i],w);
    if(w<b&&len[i]>1)
        re2=1+solve(i+1,h,w*len[i]);
    return re=min(re1,re2);

}

int main()
{
    scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
        scanf("%d",&len[i]);
    sort(len+1,len+1+n,cmp);
    int an=solve(1,h,w);
    if(an<=1e5)
        printf("%d\n",an);
    else
        printf("-1\n");
    return 0;
}
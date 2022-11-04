#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
db dp[1005][1005][2];
bool vis[1005][1005][2];
void dfs(int w,int b,int f)
{
    if(vis[w][b][f])return;
    vis[w][b][f]=1;
    if(w==0)
    {
        dp[w][b][f]=f;
        return;
    }
    if(b==0)
    {
        dp[w][b][f]=1;
        return;
    }
    dp[w][b][f]=1.0*w/(w+b);
    if(f)
    {
        dfs(w,b-1,f^1);
        dp[w][b][f]+=1.0*b/(w+b)*(1-dp[w][b-1][f^1]);
    }
    else
    {
        if(b>=2)
        {
            dfs(w,b-2,f^1);
            dp[w][b][f]+=1.0*b/(w+b)*(b-1)/(w+b-1)*(1-dp[w][b-2][f^1]);
        }
        dfs(w-1,b-1,f^1);
        dp[w][b][f]+=1.0*b/(w+b)*w/(w+b-1)*(1-dp[w-1][b-1][f^1]);
    }
}
int main()
{
    int w,b;
    scanf("%d%d",&w,&b);
    dfs(w,b,0);
    printf("%.10f",dp[w][b][0]);
    return 0;
}
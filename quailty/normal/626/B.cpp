#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[205];
bool dp[205][205][205];
void dfs(int a,int b,int c)
{
    if(dp[a][b][c])return;
    dp[a][b][c]=1;
    if(a>=2)dfs(a-1,b,c);
    if(b>=2)dfs(a,b-1,c);
    if(c>=2)dfs(a,b,c-1);
    if(a>0 && b>0)dfs(a-1,b-1,c+1);
    if(a>0 && c>0)dfs(a-1,b+1,c-1);
    if(b>0 && c>0)dfs(a+1,b-1,c-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int cnt[3]={0,0,0};
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')cnt[0]++;
        if(s[i]=='G')cnt[1]++;
        if(s[i]=='R')cnt[2]++;
    }
    dfs(cnt[0],cnt[1],cnt[2]);
    if(dp[1][0][0])printf("B");
    if(dp[0][1][0])printf("G");
    if(dp[0][0][1])printf("R");
    return 0;
}
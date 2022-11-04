#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
int dis[100005];
bool vis[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
        scanf("%d",&dis[i]);
    int now=0;
    while(now>=0 && now<n)
    {
        if(vis[now])return 0*printf("INFINITE\n");
        vis[now]=1;
        if(s[now]=='<')now-=dis[now];
        else now+=dis[now];
    }
    printf("FINITE\n");
    return 0;
}
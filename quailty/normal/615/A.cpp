#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool vis[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        while(x--)
        {
            int y;
            scanf("%d",&y);
            vis[y]=1;
        }
    }
    bool isok=1;
    for(int i=1;i<=m;i++)
        isok&=vis[i];
    printf("%s\n",(isok ? "YES" : "NO"));
    return 0;
}
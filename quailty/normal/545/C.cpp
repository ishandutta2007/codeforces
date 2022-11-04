#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct tree
{
    int x,h;
}t[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&t[i].x,&t[i].h);
    }
    int now=t[1].x-t[1].h-1,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i].x-t[i].h>now)
        {
            ans++;
            now=t[i].x;
        }
        else if(i==n || t[i].x+t[i].h<t[i+1].x)
        {
            ans++;
            now=t[i].x+t[i].h;
        }
        else
        {
            now=t[i].x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
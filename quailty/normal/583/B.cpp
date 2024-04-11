#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
bool vis[MAXN];
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=-1,dir=0,now=0;
    while(1)
    {
        bool flag=0;
        if(dir==0)
        {
            for(int i=1;i<=n;i++)
                if(!vis[i] && a[i]<=now)
                {
                    vis[i]=1;
                    now++;
                    flag=1;
                }
        }
        else
        {
            for(int i=n;i>=1;i--)
                if(!vis[i] && a[i]<=now)
                {
                    vis[i]=1;
                    now++;
                    flag=1;
                }
        }
        if(!flag)break;
        dir^=1;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
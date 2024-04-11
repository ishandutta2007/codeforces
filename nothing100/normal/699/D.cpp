#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define mo 1000000007
using namespace std;
int n,a[200100],f[200100],time,vis[200100],ans,h;
int get(int x)
{
    if (f[x]==0) return x;
    f[x]=get(f[x]);
    return f[x];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==i) h=i;
        int o=get(i);
        int p=get(a[i]);
        if (o!=p) f[o]=p;
    }
    if (!h)
    {
        int tmp=1;
        vis[1]=++time;
        while (!vis[a[tmp]])
        {
            vis[a[tmp]]=time;
            tmp=a[tmp];
        }
        ++ans;
        a[tmp]=tmp;
        h=tmp;
    }
    for (int i=1;i<=n;i++)
    if (!vis[i])
    {
        vis[i]=++time;
        int tmp=i;
        while (!vis[a[tmp]])
        {
            vis[a[tmp]]=time;
            tmp=a[tmp];
        }
        if (vis[a[tmp]]==time)
        {
            if (tmp!=h)
            {
                ans++;
                a[tmp]=h;
            }
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
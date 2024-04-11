#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
int a[MAXN],res[MAXN];
bool vis[MAXN];
set<int>s;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])s.insert(i);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=n && !vis[a[i]])
        {
            res[i]=a[i];
            vis[a[i]]=1;
        }
        else
        {
            res[i]=*s.begin();
            s.erase(s.begin());
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}
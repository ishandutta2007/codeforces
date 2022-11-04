#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int p[MAXN],vis[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int cir=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        cir++;
        int t=i;
        do
        {
            vis[t]=1;
            t=p[t];
        }
        while(t!=i);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int b;
        scanf("%d",&b);
        cnt+=b;
    }
    printf("%d",(cir>1 ? cir : 0)+(cnt&1 ? 0 : 1));
    return 0;
}
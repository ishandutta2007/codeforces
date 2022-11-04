#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    map<int,int> mi,mx;
    for(int i=1;i<=n;i++)
    {
        int u;
        scanf("%d",&u);
        if(!mi.count(u))mi[u]=i;
        mx[u]=i;
    }
    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(!mi.count(a) || !mx.count(b))printf("NO\n");
        else printf("%s\n",mi[a]<=mx[b] ? "YES" : "NO");
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
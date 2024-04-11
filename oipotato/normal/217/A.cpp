#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int fa[110];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int x[110],y[110],n;scanf("%d",&n);
        rep(i,n)scanf("%d%d",&x[i],&y[i]);
        rep(i,n)fa[i]=i;
        rep(i,n)rep(j,i-1)if(x[i]==x[j]||y[i]==y[j])fa[find(i)]=find(j);
        int ans=0;
        rep(i,n)if(find(i)==i)ans++;
        printf("%d\n",ans-1);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int fa[1010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(int x1,int y1,int x2,int y2){return x1*y2==y1*x2;}
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n,x0,y0;scanf("%d%d%d",&n,&x0,&y0);
        int x[1010],y[1010];rep(i,n)scanf("%d%d",&x[i],&y[i]);
        rep(i,n)fa[i]=i;
        rep(i,n)rep(j,i-1)if(check(x[i]-x0,y[i]-y0,x[j]-x0,y[j]-y0))fa[find(i)]=find(j);
        int ans=0;
        rep(i,n)if(find(i)==i)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
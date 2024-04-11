#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
struct DSU
{
    int fa[MAXN>>1],w[MAXN>>1];
    void Init(int n)
    {
        for(int i=0;i<=n;i++)
            fa[i]=i,w[i]=0;
    }
    int Find(int x)
    {
        if(x==fa[x])return x;
        int f=Find(fa[x]);
        w[x]^=w[fa[x]];
        return fa[x]=f;
    }
    int Union(int x,int y,int z)
    {
        int fx=Find(x),fy=Find(y);
        if(fx==fy)return w[x]^w[y]^z^1;
        return w[fx]=w[x]^w[y]^z,fa[fx]=fy,1;
    }
    int Block(int n)
    {
        int cnt=0;
        for(int i=0;i<=n;i++)
            cnt+=(Find(i)==i);
        return cnt;
    }
}odd,eve;
int main()
{
    int n,k,zr=1;
    scanf("%d%d",&n,&k);
    odd.Init(n-n/2);
    eve.Init(n/2);
    for(int i=1;i<=k;i++)
    {
        int x,y,z;
        char ty[5];
        scanf("%d%d%s",&x,&y,ty);
        z=(*ty=='o');
        int l=y-x+1,r=y+x-1;
        if(l<=0)l=2-l;
        if(r>=n+1)r=2*n-r;
        l=(l+1)/2,r=(r+1)/2;
        if((x+y)%2==0)zr&=odd.Union(l-1,r,z);
        else zr&=eve.Union(l-1,r,z);
    }
    int sum=odd.Block(n-n/2)+eve.Block(n/2)-2,res=1;
    for(int i=1;i<=sum;i++)res=2*res%Mod;
    return 0*printf("%d\n",zr*res);
}
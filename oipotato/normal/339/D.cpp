#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=(1<<17)+10;
int tree[N<<2],typ[N<<2],a[N],n,m;
void build(int p,int le,int ri)
{
    if(le==ri){typ[p]=1;tree[p]=a[le];return;}
    int mid=(le+ri)>>1;
    build(p<<1,le,mid);
    build(p<<1|1,mid+1,ri);
    typ[p]=typ[p<<1]^1;
    if(typ[p])tree[p]=tree[p<<1]^tree[p<<1|1];
    else tree[p]=tree[p<<1]|tree[p<<1|1];
}
void change(int p,int le,int ri,int x,int y)
{
    if(le==ri){tree[p]=y;return;}
    int mid=(le+ri)>>1;
    if(x<=mid)change(p<<1,le,mid,x,y);
    else change(p<<1|1,mid+1,ri,x,y);
    if(typ[p])tree[p]=tree[p<<1]^tree[p<<1|1];
    else tree[p]=tree[p<<1]|tree[p<<1|1];
}
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,(1<<n))scanf("%d",&a[i]);
    build(1,1,1<<n);
    rep(i,m)
    {
        int p,b;scanf("%d%d",&p,&b);
        change(1,1,1<<n,p,b);
        printf("%d\n",tree[1]);
    }
    return 0;
}
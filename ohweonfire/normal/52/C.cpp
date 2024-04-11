#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <cstdlib>
#include <bitset>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=200005;
struct segment{
    int l,r;
    LL val,inc;
};
inline LL min(LL a,LL b)
{
if(a<b)
    return a;
else
    return b;
}
segment seg[maxn*4];
bool use[maxn*4];
int a[maxn];
LL create(int l,int r,int t)
{
    seg[t].inc=0;
    use[t]=true;
    seg[t].l=l;
    seg[t].r=r;
    if(l==r)
        seg[t].val=a[l];
    else
    {
        int mid=l+r>>1;
        seg[t].val=min(create(l,mid,t<<1),create(mid+1,r,(t<<1)+1));
    }
    return seg[t].val;
}
void add(int l,int r,int t,int &val)
{
    if(l==seg[t].l&&r==seg[t].r)
    {
        seg[t].val+=val;
        seg[t].inc+=val;
        return;
    }
    int mid=seg[t].l+seg[t].r>>1;
    if(r<=mid)
        add(l,r,(t<<1),val);
    else if(l>mid)
        add(l,r,(t<<1)+1,val);
    else
    {
        add(l,mid,(t<<1),val);
        add(mid+1,r,(t<<1)+1,val);
    }
    seg[t].val=min(seg[t<<1].val,seg[(t<<1)+1].val)+seg[t].inc;
}
LL Query(int l,int r,int t)
{
    if(seg[t].l==l&&seg[t].r==r)
        return seg[t].val;
    int mid=seg[t].l+seg[t].r>>1;
    if(r<=mid)
        return seg[t].inc+Query(l,r,(t<<1));
    else if(l>mid)
        return seg[t].inc+Query(l,r,(t<<1)+1);
    else
        return seg[t].inc+min(Query(l,mid,t<<1),Query(mid+1,r,(t<<1)+1));
}
inline bool get(int &x)
{
    x=0;
    bool neg;
    char ch=getchar();
    while(ch!='\n'&&(ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='\n')
        return false;
    if(ch=='-')
    {
        for(ch=getchar();ch>='0'&&ch<='9';ch=getchar())
            x=x*10+ch-'0';
        x*=-1;
    }
    else
    {
        for(;ch>='0'&&ch<='9';ch=getchar())
            x=x*10+ch-'0';
    }
    return true;
}
void run()
{
    for(int i=1;i<maxn*4;i++)
        if(use[i])
            printf("%d %d %I64d %I64d\n",seg[i].l,seg[i].r,seg[i].val,seg[i].inc);
}
int main()
{
    int l,r,v,n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    create(0,n-1,1);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&l,&r);
        if(get(v))
        {
            if(l<=r)
                add(l,r,1,v);
            else
            {
                add(l,n-1,1,v);
                add(0,r,1,v);
            }
        }
        else
        {
            if(l<=r)
                printf("%I64d\n",Query(l,r,1));
            else
                printf("%I64d\n",min(Query(l,n-1,1),Query(0,r,1)));
        }
        //run();
    }
    return 0;
}
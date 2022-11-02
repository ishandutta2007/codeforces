#include<bits/stdc++.h>
#define sz 101010
using namespace std;
typedef long long ll;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
	#endif
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,m;
ll a[sz];
ll tr[sz<<2],mx[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushup(int k){tr[k]=tr[ls]+tr[rs];mx[k]=max(mx[ls],mx[rs]);}
ll query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return tr[k];
	int mid=(l+r)>>1;
	ll ret=0;
	if (x<=mid) ret+=query(lson,x,y);
	if (y>mid) ret+=query(rson,x,y);
	return ret;
}
void modify(int k,int l,int r,int pos,int x)
{
	if (l==r) 
		return (void)(tr[k]=mx[k]=x);
	int mid=(l+r)>>1;
	if (pos<=mid) modify(lson,pos,x);
	else modify(rson,pos,x);
	pushup(k);
}
void modify(int k,int l,int r,int x,int y,int mod)
{
	if (l==r) return (void)(tr[k]=(mx[k]%=mod));
	int mid=(l+r)>>1;
	if (x<=mid&&mx[ls]>=mod) modify(lson,x,y,mod);
	if (y>mid&&mx[rs]>=mod) modify(rson,x,y,mod);
	pushup(k);
}
void build(int k,int l,int r)
{
	if (l==r) return (void)(tr[k]=mx[k]=a[l]);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(k);
}
int main()
{
	file();
	int i,j,k,x,y,z;
	read>>n>>m;
	for (i=1;i<=n;i++) read>>a[i];
	build(1,1,n);
	while (m--)
	{
		read>>z>>x>>y;
		if (z==1) printf("%lld\n",query(1,1,n,x,y));
		else if (z==2) read>>z,modify(1,1,n,x,y,z);
		else modify(1,1,n,x,y);
	}
}
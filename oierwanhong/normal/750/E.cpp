#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
char s[MAXN];
int n;
struct node
{
	int a[5][5];
	node(){memset(a,0xcf,sizeof a);}
	node(int b[5][5]){memcpy(a,b,sizeof a);}
}t[MAXN<<2|1];
int a[5][5];
node operator+ (node tl,node tr)
{
	memset(a,0xcf,sizeof a);
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			for(int k=0;k<5;++k)umax(a[i][k],tl.a[i][j]+tr.a[j][k]);
	return node(a);
}
namespace sgt
{
#define rt t[num]
	void init(un l=1,un r=n,un num=1)
	{
		if(l==r)
		{
			for(int i=0;i<5;++i)rt.a[i][i]=1;
			if(s[l]=='2')rt.a[0][0]=0, rt.a[0][1]=1;
			else if(s[l]=='0')rt.a[1][1]=0, rt.a[1][2]=1;
			else if(s[l]=='1')rt.a[2][2]=0, rt.a[2][3]=1;
			else if(s[l]=='7')rt.a[3][3]=0, rt.a[3][4]=1;
			else if(s[l]=='6')rt.a[3][3]=0, rt.a[4][4]=0;
			return;
		}
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
		rt=t[num<<1]+t[num<<1|1];
	}
	node Query(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt;
		un mid=(l+r)>>1;
		if(qr<=mid)return Query(ql,qr,l,mid,num<<1);
		if(ql>mid)return Query(ql,qr,mid+1,r,num<<1|1);
		return Query(ql,qr,l,mid,num<<1)+Query(ql,qr,mid+1,r,num<<1|1);
	}
}
int main()
{
	n=read();
	int m=read();
	scanf("%s",s+1);
	sgt::init();
	while(m--)
	{
		int l=read(),r=read();
		node res=sgt::Query(l,r);
		if(res.a[0][4]<0)puts("-1");
		else printf("%d\n",r-l+1-res.a[0][4]);
	}
	return 0;
}
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
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
char a[MAXN];
int n,m;
struct Segment_Tree
{
	struct node
	{
		int f[4][4];
	}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void pushup(un num)
	{
		memset(rt.f,0x3f,sizeof rt.f);
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				for(int k=0;k<3;++k)umin(rt.f[i][j],tl.f[i][k]+tr.f[k][j]);
	}
	void init(un l=1,un r=n,un num=1)
	{
		if(l==r)
		{
			int c= a[l]-'a'+1;
			memset(rt.f,0x3f,sizeof rt.f);
			for(int x=1;x<=3;++x)
				umin(rt.f[0][x==1],int(x!=c)),
				umin(rt.f[1][1+(x==2)], int(x!=c)),
				umin(rt.f[2][2+(x==3)], int(x!=c));
			return;
		}
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
		pushup(num);
	}
	void modify(un pos,int c,un l=1,un r=n,un num=1)
	{
		if(l==r)
		{
			memset(rt.f,0x3f,sizeof rt.f);
			for(int x=1;x<=3;++x)
				umin(rt.f[0][x==1],int(x!=c)),
				umin(rt.f[1][1+(x==2)], int(x!=c)),
				umin(rt.f[2][2+(x==3)], int(x!=c));
			return;
		}
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,c,l,mid,num<<1);
		else modify(pos,c,mid+1,r,num<<1|1);
		pushup(num);
	}
	int Query()
	{
		int res=1e9+233;
		for(int i=0;i<3;++i)umin(res,t[1].f[0][i]);
		return res;
	}
}sgt;
int main()
{
	n=read(),m=read();
	scanf("%s",a+1);
	sgt.init();
	while(m--)
	{
		int x=read();
		char c=getchar();
		while(c!='a'&&c!='b'&&c!='c')c=getchar();
		sgt.modify(x,c-'a'+1);
		printf("%d\n",sgt.Query());
	}
	return 0;
}
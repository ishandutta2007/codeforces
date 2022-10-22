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
const int MAXN = 400011,mod = 1e9+7;
struct matrix
{
	int a[3][3];
	matrix(){memset(a,0,sizeof a);}
	matrix(int b[3][3]){memcpy(a,b,sizeof a);}
	matrix operator* (const matrix& you)
	{
		static int tp[3][3];
		for(int i=0;i<3;++i)
		{
			tp[i][0]=(ll(a[i][0])*you.a[0][0]+ll(a[i][1])*you.a[1][0]+ll(a[i][2])*you.a[2][0])%mod;
			tp[i][1]=(ll(a[i][0])*you.a[0][1]+ll(a[i][1])*you.a[1][1]+ll(a[i][2])*you.a[2][1])%mod;
			tp[i][2]=(ll(a[i][0])*you.a[0][2]+ll(a[i][1])*you.a[1][2]+ll(a[i][2])*you.a[2][2])%mod;
		}
		return tp;
	}
	void operator*= (const matrix& you)
	{
		static int tp[3][3];
		for(int i=0;i<3;++i)
		{
			tp[i][0]=(ll(a[i][0])*you.a[0][0]+ll(a[i][1])*you.a[1][0]+ll(a[i][2])*you.a[2][0])%mod;
			tp[i][1]=(ll(a[i][0])*you.a[0][1]+ll(a[i][1])*you.a[1][1]+ll(a[i][2])*you.a[2][1])%mod;
			tp[i][2]=(ll(a[i][0])*you.a[0][2]+ll(a[i][1])*you.a[1][2]+ll(a[i][2])*you.a[2][2])%mod;
		}
		memcpy(a,tp,sizeof a);
	}
}I;
int L;
struct Segment_Tree
{
	matrix t[MAXN<<2|1];
#define rt t[num]
	void pushdown(un num)
	{
		t[num<<1]*=rt,t[num<<1|1]*=rt;
		rt=I;
	}
	void init(un l=1,un r=L,un num=1)
	{
		if(l==r){rt.a[0][2]=1;return;}
		rt=I;
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
	}
	void Mul(un ql,un qr,const matrix& k,un l=1,un r=L,un num=1)
	{
		if(ql<=l&&r<=qr){rt*=k;return;}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)Mul(ql,qr,k,l,mid,num<<1);
		if(qr>mid)Mul(ql,qr,k,mid+1,r,num<<1|1);
	}
	matrix Query(un pos,un l=1,un r=L,un num=1)
	{
		if(l==r)return rt;
		pushdown(num);
		un mid=(l+r)>>1;
		if(pos<=mid)return Query(pos,l,mid,num<<1);
		else return Query(pos,mid+1,r,num<<1|1);
	}
}sgt;
int rb[MAXN];
int p[MAXN];
bool used[MAXN];
int main()
{
	I.a[0][0]=I.a[1][1]=I.a[2][2]=1;
	int n=read();
	L=2*n;
	for(int i=1;i<=n;++i){int l=read(),r=read();p[r]=l,rb[i]=r;}
	int t=read();
	for(int i=1;i<=t;++i)used[rb[read()]]=1;
	sgt.init();
	for(int r=1;r<=2*n;++r)
	{
		if(!p[r])continue;
		if(used[r])
		{
			matrix tp=sgt.Query(p[r]+1);
			matrix M;
			M.a[0][0]=M.a[0][1]=1,M.a[2][0]=(tp.a[0][0]+1)%mod,M.a[2][1]=(tp.a[0][1]+1)%mod;
			M.a[2][2]=1;
			sgt.Mul(1,p[r],M);
		}
		else
		{
			matrix tp=sgt.Query(p[r]+1);
			matrix M;
			M.a[0][0]=M.a[1][1]=M.a[2][2]=1;
			M.a[2][0]=(tp.a[0][0]+1)%mod;
			sgt.Mul(1,p[r],M);
		}
	}
	printf("%d\n",(sgt.Query(1)).a[0][1]);
	return 0;
}
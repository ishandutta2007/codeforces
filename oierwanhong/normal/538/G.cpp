#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<ll,ll> pii;
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
#define Fail puts("NO"),exit(0);
const ll MAXN = 2000011;
struct one
{
	ll a,x,k;//a*f[m]+f[x]=k
	bool operator< (const one& you)const{return x<you.x;}
}a[MAXN],b[MAXN];
int res[MAXN];
ll cdiv(ll a,ll b)
{
	if(b<0)a=-a,b=-b;
	return (a+b-1)/b;
}
ll fdiv(ll a,ll b)
{
	if(b<0)a=-a,b=-b;
	return a/b;
}
void solve(one* a,int n,int m,int coef)
{
	std::sort(a,a+n+1);
	ll lb=0,rb=m;
	for(int i=1;i<=n;++i)
	{
		ll p=a[i].a-a[i-1].a;
		if(p==0)
		{
			if(a[i].k-a[i-1].k>a[i].x-a[i-1].x)Fail;
		}
		else if(p>0)
		{
			umax(lb,cdiv((a[i].k-a[i-1].k)-(a[i].x-a[i-1].x),p));
			umin(rb,fdiv(a[i].k-a[i-1].k,p));
		}
		else
		{
			umax(lb,cdiv(a[i].k-a[i-1].k,p));
			umin(rb,fdiv((a[i].k-a[i-1].k)-(a[i].x-a[i-1].x),p));
		}
	}
	if(lb>rb)Fail;
	for(int i=1;i<=n;++i)
	{
		ll cur=(a[i].k-a[i-1].k)-(a[i].a-a[i-1].a)*lb;
		for(int x=a[i-1].x+1;x<=a[i].x;++x)
		{
			if(cur)res[x]+=coef,--cur;
		}
	}
}
int main()
{
	int n=read(),m=read();
	a[0]=one{0,0,0},a[n+1]=one{-1,m,0};
	b[0]=one{0,0,0},b[n+1]=one{-1,m,0};
	for(int i=1;i<=n;++i)
	{
		ll t=read(),x1=read(),y1=read();
		if(((x1+y1)&1)!=(t&1))Fail;
		ll x=(x1+y1+t)>>1,y=(y1-x1+t)>>1;
		a[i]=one{t/m,t%m,x},b[i]=one{t/m,t%m,y};
	}
	solve(a,n+1,m,2),solve(b,n+1,m,1);
	for(int i=1;i<=m;++i)
		if(res[i]==0)putchar('D');
		else if(res[i]==1)putchar('L');
		else if(res[i]==2)putchar('R');
		else putchar('U');
	puts("");
	return 0;
}
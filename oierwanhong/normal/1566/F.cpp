#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
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
const int MAXN = 500011;
const ll LINF=1e18;
struct one
{
	ll l,r,sp;
	bool operator< (const one& you)const
	{
		if(l==you.l)return r==you.r?sp<you.sp:r>you.r;
		return l<you.l;
	}
}a[MAXN];
ll f[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)a[i].l=a[i].r=read(),a[i].sp=1;
		for(int i=n+1;i<=n+m;++i)a[i].l=read(),a[i].r=read(),a[i].sp=0;
		std::sort(a+1,a+n+m+1);
		int nxt=0;
		for(int i=1;i<=n+m;++i)
		{
			while(nxt&&a[nxt].r>=a[i].r)--nxt;
			a[++nxt]=a[i];
		}
		n=nxt;
		int p=0;
		ll minv1=LINF,minv2=LINF;
		for(int i=1;i<=n;++i)
		{
			if(a[i].sp)
			{
				while(p<i)
					umin(minv1,f[p]-a[i].l-a[p+1].r),
					umin(minv2,f[p]+a[i].l-a[p+1].r-a[p+1].r),
						++p;
			}
			f[i]=min(LINF,min(minv1+a[i].l+a[i].l,minv2+a[i].l));
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
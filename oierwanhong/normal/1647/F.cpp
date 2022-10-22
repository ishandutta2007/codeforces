#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011,INF = 1e9+233;
int a[MAXN];
int fx[MAXN],diff=0;
int n;
int lim1[MAXN],lim2[MAXN];
bool fail[MAXN];
int solve()
{
	int p=0;
	for(int i=1;i<=n;++i)
		if(a[i]==n){p=i;break;}
	int fir=0,sec=0;
	for(int i=1;i<=p;++i)
		if(fir<a[i])fir=a[i];
		else if(sec<a[i])sec=a[i];
		else
		{
			//fprintf(stderr,"Fail at %d\n",i);
			return 0;
		}
	memset(fail,0,sizeof fail);
	for(int i=n;i>p;--i)
	{
		lim1[i]=lim1[i+1],lim2[i]=lim2[i+1];
		if(lim1[i]<a[i])lim1[i]=a[i];
		else if(lim2[i]<a[i])lim2[i]=a[i];
		else
		{
			for(int j=p+1;j<=i;++j)fail[j]=1;
			break;
		}
	}

	//F  only contains three part!
	int s1=sec,v1=a[p],s2=sec,v2=a[p];
	//printf("[%d,%d,%d] [%d,%d,%d]\n",s1,s2-1,v1,s2,n,v2);
	int res=0;
	for(int i=p+1;i<=n;++i)
	{
		int r=n+1,nowf=v2;
		if(s1<s2&&v1>a[i])r=s1;
		else if(v2>a[i])r=s2;
		if(s2<a[i])nowf=v2;
		else if(s1<a[i])nowf=v1;
		else nowf=-INF;
		//printf("r=%d,nowf=%d\n",r,nowf);
		int ns1,nv1,ns2,nv2;
		if(a[i]>=nowf)
		{
			if(r<=a[i])ns1=r,nv1=a[i],ns2=r,nv2=a[i];
			else
			{
				ns1=a[i],nv1=nowf;
				ns2=r,nv2=a[i];
			}
		}
		else
		{
			if(a[i]<=r)ns1=a[i],nv1=nowf,ns2=a[i],nv2=nowf;
			else
			{
			ns1=r,nv1=a[i];
			ns2=a[i],nv2=nowf;
			}
		}
		s1=ns1,v1=nv1,s2=ns2,v2=nv2;
		//printf("i=%d,[%d,%d,%d],[%d,%d,%d]\n",i,s1,s2-1,v1,s2,n,v2);
		if(!fail[i])
		{
			int t;
			if(a[i]>=s2)t=v2;
			else if(a[i]>=s1)t=v1;
			if(t>a[i])res+= t>lim1[i+1]&&a[i]>lim2[i+1];
			else res+= a[i]>lim1[i+1]&&t>lim2[i+1];
		}
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)fx[++diff]=a[i]=read();
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(fx+1,fx+diff+1,a[i])-fx;
	int ans=solve();
	std::reverse(a+1,a+n+1);
	ans+=solve();
	printf("%d\n",ans);
	return 0;
}
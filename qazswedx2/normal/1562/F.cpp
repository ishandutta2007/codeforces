#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
const int B=300;
ll gcd(ll x,ll y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
	return x/gcd(x,y)*y;
}
int t,n,a[1000005],p[1000005],tans[1000005],f[1000005],pn=5e5,vis[1000005],ct;
int b[1000005];
#ifndef DEBUG
ll query(int x,int y)
{
	printf("? %d %d\n",p[x],p[y]);
	fflush(stdout);
	ll ans=0;
	scanf("%lld",&ans);
	return ans; 
}
#else
ll query(int x,int y)
{
	return lcm(b[p[x]],b[p[y]]);
}
#endif
int myrand()
{
	return ((rand()<<15)+rand())&((1u<<31)-1);
}
int main()
{
	srand(time(0));
	f[1]=1;
	for(int i=2;1ll*i*i<=pn;i++)
		if(!f[i])
		{
			for(int j=i*i;j<=pn;j+=i)
				f[j]=1;
		}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
#ifdef DEBUG
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
#endif
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=1;i<=n;i++)
			swap(p[i],p[myrand()%i+1]);
		int m=min(B,n),id=-1;
		for(int i=1;i<=m;i++)
		{
			int T=min(5000/B,n-1);
			ll ans=0;
			ct++;
			while(T--)
			{
				int u=myrand()%n+1;
				while(u==i||vis[u]==ct) u=myrand()%n+1;
				vis[u]=ct;
				ans=gcd(ans,query(i,u));
			}
			a[i]=ans;
			if(!f[a[i]])
			{
				if(id==-1||a[id]<a[i]) id=i;
			}
	//		printf("i=%d,a=%d\n",i,a[i]);
		}
		for(int i=m+1;i<=n;i++)
			a[i]=query(id,i)/a[id];
		for(int i=1;i<=n;i++)
			tans[p[i]]=a[i];
		int mx=-1e9,mn=1e9;
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,tans[i]);
			mn=min(mn,tans[i]);
		}
		if(n==3&&mx-mn+1!=n)
		{
			for(int i=1;i<=n;i++)
				if(tans[i]==mx) tans[i]/=2;
		}
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d ",tans[i]);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int B=547;
int n,m,a[300005],fir[300005],ft,b[300005],qans[300005];
ll lazy1[300005],lazy2[300005],c[300005],d[300005];
void modify(int x,int v)
{
	for(int i=x;i<fir[b[x]+1];i++)
		c[i]+=v,d[i]+=1ll*x*v;
	for(int i=b[x]+1;i<=ft;i++)
		lazy1[i]+=v,lazy2[i]+=1ll*x*v;
}
inline ll query(int x,int fl)
{
	if(fl==0) return c[x]+lazy1[b[x]];
	return d[x]+lazy2[b[x]];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		b[i]=(i-1)/B+1;
		if(!fir[b[i]]) fir[b[i]]=i,ft++;
	//	printf("i=%d,b=%d\n",i,b[i]);
	}
	fir[ft+1]=m+1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=a[i];
		for(int j=1;j<=B;j++)
			qans[j]+=u%j;
		if(u<=B)
			ans+=qans[u];
		else
		{
			ans+=query(m,1);
			for(int j=u;j<=m;j+=u)
				ans-=1ll*(query(m,0)-query(j-1,0))*u;
		}
	//	printf("i=%d,ans=%lld\n",i,ans);
		ans+=1ll*(i-1)*u;
		for(int l=1,r;l<=u;l=r+1)
		{
			r=u/(u/l);
	//		printf("l=%d,r=%d,%d,%lld\n",l,r,u/l,query(r,1)-query(l-1,1)); 
			ans-=1ll*(u/l)*(query(r,1)-query(l-1,1));
		}
		modify(u,1);
		printf("%lld ",ans); 
	}
	//printf("%lld\n",ans);
	return 0;
}
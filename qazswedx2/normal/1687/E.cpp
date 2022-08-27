#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
ll check(int *a,int len)
{
	ll ans=0;
	for(int i=1;i<=len;i++)
		for(int j=i+1;j<=len;j++)
			ans=gcd(ans,1ll*a[i]*a[j]);
	return ans;
}
void print(int *a,int len,int fl)
{
	if(fl>0)
	{
		for(int i=1;i<=fl;i++)
		{
			printf("0 %d ",len);
			for(int j=1;j<=len;j++)
				printf("%d ",a[j]);
			printf("\n");
		}
	}
	else
	{
		for(int i=1;i<=-fl;i++)
		{
			printf("1 %d ",len);
			for(int j=1;j<=len;j++)
				printf("%d ",a[j]);
			printf("\n");
		}
	}
}
int n,a[2000005],prime[2000005],p[2000005],pt,pn=2e6;
int b[100005],bt,tmp[100005],tans[100005],tt;
int main()
{
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=pt;i++)
	{
		int mn=1e9,id=0;
		int sd=1e9,id2=0;
		for(int j=1;j<=n;j++)
		{
			int u=a[j],ct=0;
			while(u%prime[i]==0) u/=prime[i],ct++;
			if(ct<mn)
			{
				sd=mn;
				id2=id;
				mn=ct;
				id=j;
			}
			else if(ct<sd)
			{
				sd=ct;
				id2=j;
			}
			if(mn==0&&sd==0) break;
		}
		if(mn!=0||sd!=0)
		{
		//	printf("i=%d,prime=%d,mn=%d,%d,id=%d,%d\n",i,prime[i],mn,sd,id,id2);
			if(id) b[++bt]=id;
			if(id2) b[++bt]=id2; 
		}
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
//	printf("---\n");
	for(int i=1;i<=bt;i++)
		tmp[i]=a[b[i]];
	ll q=check(tmp,bt);
	for(int i=1;i<=pt;i++)
	{
		if(q%prime[i]) continue;
		int mn=1e9,id=0;
		int sd=1e9,id2=0;
		for(int j=1;j<=n;j++)
		{
			int u=a[j],ct=0;
			while(u%prime[i]==0) u/=prime[i],ct++;
			if(ct<mn)
			{
				sd=mn;
				id2=id;
				mn=ct;
				id=j;
			}
			else if(ct<sd)
			{
				sd=ct;
				id2=j;
			}
			if(mn==0&&sd==0) break;
		}
	//	if(mn!=0||sd!=0)
		{
		//	printf("i=%d,prime=%d,mn=%d,%d,id=%d,%d\n",i,prime[i],mn,id,id2);
			if(id) b[++bt]=id;
			if(id2) b[++bt]=id2; 
		}
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
//	printf("---\n");
	for(int i=1;i<=bt;i++)
		tmp[i]=a[b[i]];
	q=check(tmp,bt);
	tt=1e9;
	for(int i=1;i<(1<<bt);i++)
	{
		int t=0;
		for(int j=1;j<=bt;j++)
			if(i&(1<<(j-1)))
				tmp[++t]=a[b[j]];
		if(t<=1) continue;
		ll nw=check(tmp,t);
		if(q==nw&&t<tt)
		{
			tt=0;
			for(int j=1;j<=bt;j++)
				if(i&(1<<(j-1)))
					tans[++tt]=b[j];
		}
	}
//	printf("---\n");
	int sum=0;
	for(int i=1;i<(1<<tt);i++)
	{
		int t=0;
		for(int j=1;j<=tt;j++)
			if(i&(1<<(j-1)))
				tmp[++t]=tans[j];
		int fl=t-2;
		if(t%2) fl=-fl;
		if(fl<0) fl=-fl;
		sum+=fl;
	}
	printf("%d\n",sum);
	for(int i=1;i<(1<<tt);i++)
	{
		int t=0;
		for(int j=1;j<=tt;j++)
			if(i&(1<<(j-1)))
				tmp[++t]=tans[j];
		int fl=t-2;
		if(t%2) fl=-fl;
		print(tmp,t,fl);
	}
	return 0;
}
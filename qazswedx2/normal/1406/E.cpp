#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[100005],prime[100005],pn=1e5,pt,m=100,ct,a[100005],k;
/*int b[100005];
int query(int x)
{
	int ans=0;
	for(int i=x;i<=n;i+=x)
		ans+=!b[i];
	return ans;
}
int modify(int x)
{
	int ans=query(x);
	for(int i=x;i<=n;i+=x)
		if(i!=k) b[i]=1;
	return ans;
}*/
int modify(int x)
{
	printf("B %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
int query(int x)
{
	printf("A %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
void modify2(int x)
{
	for(int i=x;i<=n;i+=x)
	{
		if(a[i]) ct--;
		a[i]=0;
	}
}
void getans(int x,int y)
{
	for(int i=y;i<=pt&&1ll*x*prime[i]<=n;i++)
		if(query(x*prime[i]))
		{
			getans(x*prime[i],y);
			return;
		}
	printf("C %d\n",x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		a[i]=1;
	ct=n;
	for(int i=2;i<=n;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=n;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	//for(int i=pt;i;i--)
	//	printf("%d ",prime[i]);
	int l=0,r=0;
	for(int i=1;i<=pt;i++)
	{
		modify(prime[i]);
		modify2(prime[i]);
		if(i%m==0)
		{
			int q=query(1);
			if(q==ct) continue;
		//	printf("q=%d,ct=%d\n",q,ct);
			l=i-99,r=i;
			break;
		}
	}
	if(!l) l=pt/m*m+1,r=pt;
//	printf("l=%d,r=%d,pt=%d\n",l,r,pt);
	for(int i=l;i<=r;i++)
		if(query(prime[i]))
		{
			getans(prime[i],i);
			return 0;
		}
	printf("C 1\n");
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
int n,m,k,ct=0;
ll f[100005],tmp[100005];
ll F(int x)
{
	ll ans;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%lld",&ans);
	if(ct&&f[2]==ans)
	{
	//	printf("---\n");
		if(k>2)
		{
			printf("! %d\n",(x==1?n:x-1));
			exit(0);
		}
		else
		{
			x=(x==1?n:x-1);
			while(1)
			{
				printf("? %d\n",x);
				fflush(stdout);
				int ans;
				scanf("%d",&ans);
				if(ans==2)
				{
					printf("! %d\n",x);
					exit(0);
				}
				x=(x==1?n:x-1);
			}
		}
	}
	for(int i=1;i<=m;i++)
		tmp[i]=f[i];
	f[1]=(tmp[m]+1)/2+tmp[2]/2;
	f[2]=tmp[1]+tmp[3]/2;
	for(int i=3;i<=m;i++)
		f[i]=(tmp[i-1]+1)/2+tmp[i+1]/2;
	ct++;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	m=min(n,2000);
	for(int i=1;i<=m;i++)
		f[i]=k;
	int x=0;
	ll nw=0;
	for(int i=1,j=0;;i+=j,j+=3)
	{
		if(i>n) i=n;
		ll q=F(i);
		if(q!=k)
		{
			x=i;
			nw=q;
			break;
		}
		if(i<n) F(i+1);
	}
	if(nw>k)
	{
		x=(x==1?n:x-1);
		while(1)
		{
			F(x);
			x=(x==1?n:x-1);
		}
	}
	else
	{
		x=(x==n?1:x+1);
		while(1)
		{
			F(x);
			x=(x==n?1:x+1);
		}
	}
	return 0;
}
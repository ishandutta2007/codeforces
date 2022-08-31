#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
bitset<7005> a[100005],tans[100005];
int n,m,p[100005],prime[100005],pn=7000,mu[100005],pt;
int main()
{
	mu[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,mu[i]=-1;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=pn;i++)
		for(int j=1;j*i<=pn;j++)
			if(mu[j]) tans[i][j*i]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			a[x].reset();
			for(int i=1;i*i<=y;i++)
				if(y%i==0)
				{
					a[x][i]=1;
					a[x][y/i]=1;
				}
		}
		if(op==2)
		{
			scanf("%d",&z);
			a[x]=a[y]^a[z];
		}
		if(op==3)
		{
			scanf("%d",&z);
			a[x]=a[y]&a[z];
		}
		if(op==4)
		{
			printf("%d",(int)((a[x]&tans[y]).count())%2);
		}
	}
	return 0;
}
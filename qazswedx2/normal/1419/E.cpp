#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,a[105],b[105],at,f[100005],ft,c[105];
vector<int> val[105],val2[105];
void getans(int x)
{
	at=0;
	for(int i=2;1ll*i*i<=x;i++)
		if(x%i==0)
		{
			at++;
			a[at]=i;
			b[at]=0;
			while(x%i==0) x/=i,b[at]++;
		}
	if(x!=1)
	{
		at++;
		a[at]=x,b[at]=1;
	}
}
void getans2(int x)
{
	ft=0;
	for(int i=1;1ll*i*i<=x;i++)
		if(x%i==0)
		{
			if(i!=1)f[++ft]=i;
			if(i!=x/i) f[++ft]=x/i;
		}
}
void print(vector<int> v)
{
	int sz=v.size();
	for(int i=0;i<sz;i++)
		printf("%d ",v[i]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getans(n);
		getans2(n);
		if(at==1)
		{
			for(int i=1;i<=ft;i++)
				printf("%d ",f[i]);
			printf("\n0\n");
			continue;
		}
		if(at==2)
		{
			if(b[1]==1&&b[2]==1)
			{
				for(int i=1;i<=ft;i++)
					printf("%d ",f[i]);
				printf("\n1\n");
				continue;
			}
			int x=a[1],y=a[2],z=a[1]*a[2];
			val[1].clear();
			val[2].clear();
			val[3].clear();
			for(int i=1;i<=ft;i++)
			{
				if(f[i]%z==0)
				{
					if(f[i]!=z) val[3].push_back(f[i]);
					continue;
				}
				if(f[i]%x==0)
				{
					val[1].push_back(f[i]);
					continue;
				}
				if(f[i]%y==0)
				{
					val[2].push_back(f[i]);
					continue;
				}
			}
			print(val[1]);
			print(val[3]);
			print(val[2]);
			printf("%d\n0\n",z);
			continue;
		}
		if(at>=3)
		{
			for(int i=1;i<at;i++)
				c[i]=a[i]*a[i+1];
			c[at]=a[at]*a[1];
			for(int i=1;i<=at;i++)
			{
				val[i].clear();
				val2[i].clear();
			}
			for(int i=1;i<=ft;i++)
			{
				int fl=0;
				for(int j=1;j<=at;j++)
					if(f[i]%c[j]==0)
					{
						val2[j].push_back(f[i]);
						fl=1;
						break;
					}
				if(fl) continue;
				for(int j=1;j<=at;j++)
					if(f[i]%a[j]==0)
					{
						val[j].push_back(f[i]);
						break;
					}
			}
			for(int i=1;i<=at;i++)
			{
				print(val[i]);
				print(val2[i]);
			}
			printf("\n0\n");
		}
	}
	return 0;
}
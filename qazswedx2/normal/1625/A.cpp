#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,l,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int x=0;
		for(int i=0;i<30;i++)
		{
			int ct0=0,ct1=0;
			for(int j=1;j<=n;j++)
				if(a[j]&(1<<i))
					ct1++;
				else ct0++;
			if(ct0<ct1) x|=(1<<i);
		}
		printf("%d\n",x);
	}
	return 0;
}
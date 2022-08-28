#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==m) ct++;
		}
		if(ct==n) printf("0\n");
		else if(ct) printf("1\n");
		else
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=a[i];
			if(sum==n*m) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}
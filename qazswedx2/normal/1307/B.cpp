#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int nw=m/a[n]+(m%a[n]!=0)+(m<a[n]),fl=1;
		for(int i=1;i<=n;i++)
			if(m==a[i])
			{
				printf("1\n");
				fl=0;
				break;
			}
		if(fl) printf("%d\n",nw);
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
int t,n,a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int fl=0,id=0;
		for(int i=1;i<n;i++)
			if(a[i]-a[i+1]>=2||a[i+1]-a[i]>=2) fl=1,id=i;
		if(fl==1) printf("YES\n%d %d\n",id,id+1);
		else printf("NO\n");
	}
	return 0;
}
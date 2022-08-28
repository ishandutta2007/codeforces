#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int fl=0;
	for(int i=1;i<n;i++)
	{
		if(i>1&&(a[i]^a[i+1])<a[i-1]) fl=1;
		if(i+2<=n&&(a[i]^a[i+1])>a[i+2]) fl=1;
	}
	if(fl)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i]^=a[i-1];
	int ans=1e9;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if((a[k]^a[j])<(a[j]^a[i-1]))
					ans=min(ans,k-i-1);
	if(ans!=1e9) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
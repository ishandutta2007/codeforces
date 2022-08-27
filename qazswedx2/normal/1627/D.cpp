#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[2000005],c[2000005],f[2000005];
int main()
{
	scanf("%d",&n);
	int m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]=1;
		m=max(m,a[i]);
	}
	int ans=0;
	for(int i=m;i>0;i--)
	{
		for(int j=i;j<=m;j+=i)
			f[i]+=c[j];
		int fl=1;
		for(int j=i*2;j<=m;j+=i)
			if(f[i]==f[j])
				fl=0;
		if(f[i]&&fl)
		{
			ans++;
			c[i]++;
			f[i]++;
		}
	}
	printf("%d\n",ans-n);
	return 0;
}
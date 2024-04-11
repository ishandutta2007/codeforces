#include<cstdio>
using namespace std;
bool ans;
int n,a[2010],m;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				ans^=1;
			}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ans^=((r-l+1)*(r-l)/2)&1;
		puts(ans?"odd":"even");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[300010],ans0[300010],ans1[300010],tans0,tans1,n,x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		y=min(i-1,n-i)*2+1;
		if(a[i]<=a[i-1]||a[i]<=a[i+1])ans1[y]=max(ans1[y],a[i]);
		else ans1[y]=max(ans1[y],max(a[i-1],a[i+1]));
		if(i-1!=n-i)y++;else y--;
		ans0[y]=max(ans0[y],a[i]);
	}
	if(n==1)
	{
		printf("%d",a[1]);
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		if((n-i)%2)
		{
			tans1=max(tans1,ans1[n-i]);
			printf("%d ",tans1);
		}
		else
		{
			tans0=max(tans0,ans0[n-i]);
			printf("%d ",tans0);
		}
	}
	printf("%d ",tans0);
	return 0;
}
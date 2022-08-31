#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1)
		{
			if(a[i]==2&&a[i-1]==1)
			{
				ans+=3;
				if(i>2&&a[i-2]==3) ans--;
			}
			if(a[i]==1&&a[i-1]==2)
				ans+=3;
			if(a[i]==1&&a[i-1]==3)
				ans+=4;
			if(a[i]==3&&a[i-1]==1)
				ans+=4;
			if(a[i]==2&&a[i-1]==3||a[i]==3&&a[i-1]==2)
			{
				ans=-1;
				break;
			}
		}
	}
	if(ans==-1) printf("Infinite");
	else
	{
		printf("Finite\n%d",ans);
	}
	return 0;
}
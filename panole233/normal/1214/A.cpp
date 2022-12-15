#include<bits/stdc++.h>
using namespace std;

int n,d,e,ans;

int main()
{
	scanf("%d%d%d",&n,&d,&e),e*=5;
	ans=100000000;
	for (int i=0; i<=n/d; i++)
	{
		int y=n-i*d;
		y-=(y/e)*e;
		ans=min(ans,y);
	}
	printf("%d\n",ans);
	return 0;
}
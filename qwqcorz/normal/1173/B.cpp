#include<bits/stdc++.h>
using namespace std;

int n,ans;

int main()
{
	scanf("%d",&n);
	ans=n/2+1;
	printf("%d\n",ans);
	for (int i=1,x=1,y=1;i<=n;i++)
	{
		printf("%d %d\n",x,y);
		if (i&1) y++;
			else x++;
	}

    return 0;
}
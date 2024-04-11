#include<bits/stdc++.h>
using namespace std;

int n,x;
long long ans,tot;

int main()
{
	scanf("%d",&n),ans=tot=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		if (tot*2<=x) x-=2*tot,ans+=tot,tot=0;
		else ans+=x/2,tot-=x/2,x&=1;
		ans+=x/3,tot+=x%3;
	}
	printf("%I64d\n",ans);
	return 0;
}
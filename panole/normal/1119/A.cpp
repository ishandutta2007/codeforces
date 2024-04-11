#include<bits/stdc++.h>
using namespace std;

int n,ans,c[300001],mi,mii,mi2; 

int main()
{
	scanf("%d",&n);
	mi=mi2=n+1,ans=mii=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&c[i]);
		if (mii==c[i]) ans=max(ans,i-mi2);
		else ans=max(ans,i-mi);
		if (i<mi) mi2=mi,mii=c[i],mi=i; else
		if (mii!=c[i]&&i<mi2) mi2=i;
	}
	printf("%d\n",ans);
	return 0;
}
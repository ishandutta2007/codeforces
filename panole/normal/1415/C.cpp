#include<bits/stdc++.h>
using namespace std;

int T,n,k,p,c1,c2,c[100010];
char s[100010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&p,&k),scanf("%s",s+1),scanf("%d%d",&c1,&c2);
		int ans=2000000000;
		for (int i=n; i>n-k; i--)
			c[i]=(s[i]=='0')*c1;
		for (int i=n-k; i>=p; i--) c[i]=(s[i]=='0')*c1+c[i+k];
		for (int i=p; i<=n; i++) ans=min(ans,c[i]+(i-p)*c2);
		printf("%d\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,k;
long long ans,nw;
char s[1000010],t[1000010];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s%s",s,t),nw=0;
	for (int i=0; i<n; i++)
	{
		nw=nw*2+t[i]-s[i];
		if (nw>=k) {ans+=1ll*(n-i)*k; break;}
		else ans+=nw+1;
	}
	printf("%lld\n",ans);
	return 0;
}
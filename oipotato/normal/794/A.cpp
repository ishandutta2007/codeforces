#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,x,ans;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(b<x&&x<c)ans++;
	}
	printf("%d",ans);
	return 0;
}
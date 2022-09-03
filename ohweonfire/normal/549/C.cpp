#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,k,odd,ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(x&1)odd++;
	}
	if(n==k)ans=odd&1;
	else if((n&1)==0)
	{
		if((k&1)==0)ans=0;
		else ans=(n/2-k/2<=odd);
	}
	else
	{
		if((k&1)==0)ans=(odd>=(n/2+1-k/2)&&odd<=(n/2+k/2));
		else ans=(n/2+k/2+1<=odd);
	}
	puts(ans?"Stannis":"Daenerys");
	return 0;
}
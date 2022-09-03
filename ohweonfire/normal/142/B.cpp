#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m;
long long ans;
int main()
{
	
		scanf("%d%d",&n,&m);
		if(n==1)
			ans=m;
		else if(m==1)
			ans=n;
		else if(n==2)
			ans=((m/4)*2+min(m&3,2))*2ll;
		else if(m==2)
			ans=((n/4)*2+min(n&3,2))*2ll;
		else
			ans=(n*1ll*m+1)/2;
		printf("%I64d\n",ans);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int t,n,m;
ll tans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		tans=0;
		for(ll i=10;i-1<=m;i*=10) tans++;
		tans*=n;
		printf("%I64d\n",tans);
	}
	return 0;
}
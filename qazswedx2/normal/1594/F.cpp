#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,s;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&s,&n,&m);
		if(n<m&&s==m)
		{
			printf("YES\n");
			continue;
		}
		ll q=n/m*m*2+n%m;
		if(s>=q) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
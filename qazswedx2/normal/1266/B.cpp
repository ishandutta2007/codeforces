#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll a;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a);
		if(a<14) 
		{
			printf("NO\n");
			continue;
		}
		a%=14;
		if(a>=1&&a<=6) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
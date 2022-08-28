#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
int a[15];
char s[15]="codeforces";
int main()
{
	scanf("%lld",&n);
	ll ans=1;
	int nw=0;
	while(ans<n)
	{
		a[nw]++;
		ans=1;
		for(int i=0;i<10;i++)
			ans*=(a[i]+1);
		nw=(nw+1)%10;
	}
	for(int i=0;i<10;i++)
		for(int j=0;j<=a[i];j++)
			printf("%c",s[i]);
	printf("\n");
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005],at;
ll m;
char s[1000005];
int main()
{
	scanf("%d%lld",&n,&m);
	scanf("%s",s+1);
	ll sum=(1<<(s[n]-'a'))-(1<<(s[n-1]-'a'));
	for(int i=1;i<=n-2;i++)
	{
		a[++at]=(1<<(s[i]-'a'+1));
		sum-=a[at]/2;
	}
	sort(a+1,a+at+1);
	m-=sum;
	for(int i=at;i>0;i--)
		if(m>=a[i]) m-=a[i];
	if(!m) printf("Yes\n");
	else printf("No\n");
	return 0;
}
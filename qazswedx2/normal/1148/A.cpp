#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,c,ans=0;
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	ans=2*c;
	if(a==b) ans+=(a+b);
	if(a>b) ans+=min(a*2-1,b*2+1);
	if(a<b) ans+=min(b*2-1,a*2+1);
	printf("%I64d",ans);
}
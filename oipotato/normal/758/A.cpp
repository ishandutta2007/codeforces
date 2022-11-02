#include<cstdio>
#include<algorithm>
using namespace std;
int x,a[110],n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);x=max(x,a[i]);}
	for(int i=1;i<=n;i++)ans+=x-a[i];
	printf("%d",ans);
	return 0;
}
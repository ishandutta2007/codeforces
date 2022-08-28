#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[1000005];
int main()
{
	scanf("%d",&n);
	f[1]=1;
	for(int i=1;i<=n;i++)
		for(int j=i*2;j<=n;j+=i)
			f[j]=max(f[j],i);
	sort(f+1,f+n+1);
	for(int i=2;i<=n;i++)
		printf("%d ",f[i]);
	return 0;
}
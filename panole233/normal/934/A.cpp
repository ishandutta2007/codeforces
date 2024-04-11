#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const long long inf=1000000000000000000ll;

long long ans,a[100001],b[100001],mi;
int n,m;

long long getmax(long long a,long long b) {return a>b?a:b;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	for (int i=1; i<=m; i++) scanf("%I64d",&b[i]);
	mi=inf;
	for (int i=1; i<=n; i++)
	{
		ans=-inf;
		for (int j=1; j<=n; j++)
			if (j!=i)
				for (int k=1; k<=m; k++) ans=getmax(ans,a[j]*b[k]);
		if (ans<mi) mi=ans;
	}
	printf("%I64d\n",mi);	
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[110];
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)
	{
		int p=1;for(int j=2;j<=i;j++)if(a[j]>a[p])p=j;
		for(int j=p;j<i;j++)swap(a[j],a[j+1]),printf("%d %d\n",j,j+1);
	}
	return 0;
}
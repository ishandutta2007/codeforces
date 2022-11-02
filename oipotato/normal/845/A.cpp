#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	printf(a[n]<a[n+1]?"YES\n":"NO\n");
	return 0;
}
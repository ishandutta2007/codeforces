#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	int mn=1e9;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mn=min(mn,a[i]);
	printf("%d",2+(a[3]^mn));
	return 0;
}
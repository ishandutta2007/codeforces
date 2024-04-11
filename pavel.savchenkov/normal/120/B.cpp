#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+1];
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=k;i<=n;i++)
		if (a[i]==1) {printf("%d",i);return 0;}
	for (int i=1;i<k;i++)
		if (a[i]==1) {printf("%d",i);return 0;}
	return 0;
}
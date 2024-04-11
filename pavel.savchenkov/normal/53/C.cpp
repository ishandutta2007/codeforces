#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int l=1; int r=n; int ans=0;
	while (ans<n)
	{
		printf("%d ",l);ans++;
		if (ans>=n) break;
		printf("%d ",r);ans++;
		l++;r--;
	}
	return 0;
}
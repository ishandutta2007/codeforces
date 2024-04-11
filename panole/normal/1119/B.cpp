#include<bits/stdc++.h>
using namespace std;

int n,h,a[1001];

int main()
{
	scanf("%d%d",&n,&h); long long H;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int j=1; j<=n; j++)
	{
		sort(a+1,a+1+j),H=0;
		if (j&1) {for (int i=1; i<=j; i+=2) H+=a[i];}
		else {for (int i=2; i<=j; i+=2) H+=a[i];}
		if (h<H) return printf("%d\n",j-1),0;
	}
	printf("%d\n",n);
	return 0;
}
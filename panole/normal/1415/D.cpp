#include<bits/stdc++.h>
using namespace std;

int n,a[100010];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	if (n>100) return puts("1"),0;
	int ans=100000;
	for (int i=1; i<n; i++)
		for (int nw1=a[i],j=i; j; j--,nw1^=a[j])
			for (int nw2=a[i+1],k=i+1; k<=n; k++,nw2^=a[k])
				if (nw1>nw2) ans=min(ans,i-j+k-i-1);
	printf("%d\n",ans==100000?-1:ans);
	return 0;
}
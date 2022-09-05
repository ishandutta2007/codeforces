#include<bits/stdc++.h>
using namespace std;

int n,a[200010],b[200010],po;

int main()
{
	scanf("%d",&n),po=1;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%d",&b[i]);
	int nw=0;
	for (int i=1; i<=n; i++) if (b[i]==1) {nw=i; break;}
	if (nw)
	{
		bool bo=1;
		for (int i=nw+1; i<=n; i++) if (b[i]!=i-nw+1) {bo=0; break;}
		if (bo)
		{
			for (int i=1; i<nw; i++) if (b[i]&&b[i]-b[n]<=i) {bo=0; break;}
			if (bo) return printf("%d\n",nw-1),0;
		}
	}
	for (int i=1; i<=n; i++) if (b[i]) po=max(po,i+2-b[i]);
	printf("%d\n",po+n-1);
	return 0;
}
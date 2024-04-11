#include<bits/stdc++.h>
using namespace std;

int n,a[20];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=0; i<(1<<n); i++)
	{
		int nw=0;
		for (int j=0; j<n; j++)
			if (i>>j&1) nw-=a[j+1]; else nw+=a[j+1];
		if (nw%360==0) {puts("YES"); return 0;}
	}
	puts("NO");
	return 0;
}
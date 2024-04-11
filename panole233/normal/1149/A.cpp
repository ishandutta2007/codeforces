#include<bits/stdc++.h>
using namespace std;

int n,cnt1,cnt2,x;
bool p[1000001];

int main()
{
	memset(p,1,sizeof(p));
	for (int i=2; i<=1000000; i++) if (p[i])
		for (int j=(i<<1); j<=1000000; j+=i) p[j]=0;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&x);
		if (x==1) cnt1++;
		else cnt2++;
	}
	if (cnt2) printf("2 "),cnt2--;
	if (cnt1) printf("1 "),cnt1--;
	for (int i=1; i<=cnt2; i++) printf("2 ");
	for (int i=1; i<=cnt1; i++) printf("1 ");
	return puts(""),0;
}
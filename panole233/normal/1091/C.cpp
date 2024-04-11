#include<bits/stdc++.h>
using namespace std;

int n,an;
long long ans[100001];

long long Calc(int x) {return 1ll*x*(x-1)/2;}

long long calc(int x)
{
	return 1ll*x*Calc(n/x)+n/x;
}

int main()
{
	scanf("%d",&n); an=0;
	for (int i=1; i*i<=n; i++)
	if (n%i==0)
	{
		ans[++an]=calc(i);
		if (i*i!=n) ans[++an]=calc(n/i);
	}
	sort(ans+1,ans+1+an);
	for (int i=1; i<=an; i++) printf("%I64d ",ans[i]); puts("");
	return 0;
}
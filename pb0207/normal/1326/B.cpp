#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int n;

ll b[N],a[N];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	ll mx=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=mx+b[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
}
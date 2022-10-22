#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int T;

ll a,b,n,m;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
		if(n+m>a+b)
			puts("No");
		else
		{
			ll mn=min(a,b);
			if(mn>=m)
				puts("Yes");
			else
				puts("No");
		}
	} 
}
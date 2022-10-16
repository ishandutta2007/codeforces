#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m;

int main()
{
	long long i,k;
	pair<long long,long long> mxe={0,-1};
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		mxe=max(mxe,{(k-1)/m+1,i});
	}
	printf("%lld\n",mxe.sc);
}
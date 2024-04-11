#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
long long a[100010];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&a[i]);
	printf("1 1\n%lld\n",-a[1]);a[1]=0;
	if(n==1)
	{
		printf("1 1\n0\n1 1\n0\n");
		return 0;
	}
	printf("%d %d\n",2,n);
	for(int i=2;i<=n;i++)
	{
		long long tmp=1ll*(-(a[i]%n))*(n-1)*(n-1);
		printf("%lld%c",tmp," \n"[i==n]);
		a[i]+=tmp;
	}
	printf("%d %d\n",1,n);
	rep(i,n)printf("%lld%c",-a[i]," \n"[i==n]);
	return 0;
}
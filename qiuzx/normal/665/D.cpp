#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll n,a[N];
bool prm[2000010];
int main(){
	ll i,j,on=0,oc=-1;
	memset(prm,true,sizeof(prm));
	prm[0]=prm[1]=false;
	for(i=2;i<2000010;i++)
	{
		if(!prm[i])
		{
			continue;
		}
		for(j=i*2;j<2000010;j+=i)
		{
			prm[j]=false;
		}
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==1)
		{
			on++;
		}
		else if(prm[a[i]+1])
		{
			oc=a[i];
		}
	}
	if(on)
	{
		if(on+(oc!=-1)>1)
		{
			printf("%lld\n",on+(oc!=-1));
			for(i=0;i<on;i++)
			{
				printf("1 ");
			}
			if(oc!=-1)
			{
				printf("%lld",oc);
			}
			puts("");
			return 0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(prm[a[i]+a[j]])
			{
				puts("2");
				printf("%lld %lld\n",a[i],a[j]);
				return 0;
			}
		}
	}
	puts("1");
	printf("%lld\n",a[0]);
	return 0;
}
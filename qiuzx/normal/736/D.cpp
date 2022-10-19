//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 4010
using namespace std;
ll n,m,edx[500010],edy[500010];
bitset<N> a[N>>1];
int main(){
	ll i,j,k;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&edx[i],&edy[i]);
		edx[i]--,edy[i]--;
		a[edx[i]][edy[i]]=1;
	}
	for(i=0;i<n;i++)
	{
		a[i][i+n]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[j][i])
			{
				break;
			}
		}
		swap(a[i],a[j]);
		if(!a[i][i])
		{
			a[i]=0;
		}
		for(j=0;j<n;j++)
		{
			if(j!=i&&a[j][i])
			{
				a[j]^=a[i];
			}
		}
	}
	for(i=0;i<m;i++)
	{
		puts(a[edy[i]][edx[i]+n]?"NO":"YES");
	}
	return 0;
}
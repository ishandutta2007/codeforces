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
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,a[N],ans=LINF;
int main(){
	ll i,j,k;
	n=rint();
	for(i=0;i<n;++i)
	{
		a[i]=rint();
	}
	for(i=1;i<=2000010;++i)
	{
		if(i*(i+1)>=a[0])
		{
			ll l=max((ll)0,i*i-a[0]),r=i*(i+1)-a[0],pre=max((ll)0,i*i-a[0]);
			for(k=i;k;k++)
			{
				j=lower_bound(a,a+n,k*(k+1)-pre+1)-a-1;
				if(a[j]+pre<=k*(k+1)&&a[j]+pre>=k*k)
				{
					r=min(r,k*(k+1)-a[j]);
				}
				if(j<n-1&&a[j+1]+pre<(k+1)*(k+1))
				{
					l=max(l,(k+1)*(k+1)-a[j+1]);
				}
				if(a[n-1]+pre<(k+1)*(k+1))
				{
					break;
				}
			}
			if(l<=r)
			{
				ans=l;
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
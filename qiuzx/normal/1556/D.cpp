//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 10010
using namespace std;
ll n,k,a[N],cur[10],cc[10],ans=0;
vector<ll> req;
int main(){
	ll i,j,mask,x;
	scanf("%lld%lld",&n,&k);
	printf("or 1 2\n");
	fflush(stdout);
	scanf("%lld",&x);
	req.push_back(x);
	printf("and 1 2\n");
	fflush(stdout);
	scanf("%lld",&x);
	req.push_back(x);
	printf("or 1 3\n");
	fflush(stdout);
	scanf("%lld",&x);
	req.push_back(x);
	printf("and 1 3\n");
	fflush(stdout);
	scanf("%lld",&x);
	req.push_back(x);
	printf("or 2 3\n");
	fflush(stdout);
	scanf("%lld",&x);
	req.push_back(x);
	printf("and 2 3\n");
	fflush(stdout);
	scanf("%lld",&x);
	req.push_back(x);
	for(i=0;i<=30;i++)
	{
		for(j=0;j<req.size();j++)
		{
			cur[j]=((req[j]>>i)&1);
		}
		for(mask=0;mask<(1<<3);mask++)
		{
			cc[0]=(mask&1);
			cc[1]=((mask>>1)&1);
			cc[2]=((mask>>2)&1);
			if((cc[0]|cc[1])==cur[0]&&(cc[0]&cc[1])==cur[1]&&(cc[0]|cc[2])==cur[2]&&(cc[0]&cc[2])==cur[3]&&(cc[1]|cc[2])==cur[4]&&(cc[1]&cc[2])==cur[5])
			{
				break;
			}
		}
		for(j=0;j<3;j++)
		{
			a[j]+=cc[j]*(1<<i);
		}
	}
	for(i=4;i<=n;i++)
	{
		printf("or 1 %lld\n",i);
		fflush(stdout);
		scanf("%lld",&x);
		printf("and 1 %lld\n",i);
		fflush(stdout);
		scanf("%lld",&j);
		a[i-1]=(a[0]^x^j);
	}
	sort(a,a+n);
	printf("finish %lld\n",a[k-1]);
	return 0;
}
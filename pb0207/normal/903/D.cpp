#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n,a[N];

ll sum;

map<int,ll>mps,mpc;

long double ans1;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		ll k=(sum-mps[a[i]]-mps[a[i]+1]-mps[a[i]-1]-(n-i-mpc[a[i]]-mpc[a[i]-1]-mpc[a[i]+1])*a[i]);
		ans1+=k;
		mps[a[i]]+=a[i];
		mpc[a[i]]++;
		sum+=a[i];
	}
	cout<<fixed<<setprecision(0)<<ans1;
}
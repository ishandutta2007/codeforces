#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod = 1000000007L;
ll *A;
ll *pre;
void precompute(ll k) {
	A = new ll[100001];
	pre = new ll[100001];
	pre[0] = 0;
	A[0] = 1L;
	for (ll i = 1; i < k; ++i)
	{
		A[i] = 1L;
		pre[i] = (pre[i-1] + A[i])%mod;
	}
	for (ll i = k; i < 100001; ++i)
	{
		A[i] = (A[i-k]+A[i-1])%mod;
		pre[i] = (pre[i-1] + A[i])%mod;
	}
}
int main()
{
	ll t, k;
	cin>>t>>k;
	precompute(k);
	while(t--) {
		ll a, b;
		cin>>a>>b;
		cout<<(pre[b] - pre[a-1]+mod)%mod<<"\n";
	}
}
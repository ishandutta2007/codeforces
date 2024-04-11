#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
    int p,base;
    int prime(ll x)
    {
    	if (x<2) return 0;
    	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
    	return 1;
    }
ll get_rand(ll l, ll r)
{
	return uniform_int_distribution<ll>(l,r)(rng);
}


ll arr[200001];
ll n,m,i,j,k,t,t1,u,v,a,b,minn=1e18;
vector<ll> factorize(ll x)
{
	vector<ll> res;
	for (ll i=2;i*i<=x;i++) if (x%i==0)
	{
		res.push_back(i);
		while (x%i==0) x/=i;
	}
	if (x>1) res.push_back(x);
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for (t=1;t<=20;t++)
	{
		j=get_rand(1,n);
		auto cur=factorize(arr[j]);
		for (ll g : cur)
		{
	//		cout<<g<<endl;
			u=0;
			for (i=1;i<=n;i++)
			{
				if (arr[i]<g) u+=g-arr[i]%g;
				else 
				u+=min(g-arr[i]%g,arr[i]%g);
			}
			minn=min(minn,u);
		}
		cur=factorize(arr[j]+1);
		for (ll g : cur)
		{
	//		cout<<g<<endl;
			u=0;
			for (i=1;i<=n;i++)
			{
				if (arr[i]<g) u+=g-arr[i]%g;
				else 
				u+=min(g-arr[i]%g,arr[i]%g);
			}
			minn=min(minn,u);
		}
		if (arr[j]>1)
		{
		
		cur=factorize(arr[j]-1);
		for (ll g : cur)
		{
	//		cout<<g<<endl;
			u=0;
			for (i=1;i<=n;i++)
			{
				if (arr[i]<g) u+=g-arr[i]%g;
				else 
				u+=min(g-arr[i]%g,arr[i]%g);
			}
			minn=min(minn,u);
		}
		}
	}
	cout<<minn;
}
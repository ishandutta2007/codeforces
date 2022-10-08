#include <bits/stdc++.h>
using namespace std;

using ll=long long;

struct Primes
{
	vector <ll> w, dp;
	int gdz(ll v)
	{
		if (v<=w.back()/v)
			return v-1;
		return w.size()-w.back()/v;
	}
	ll pi(ll n)
	{
		for (ll i=1; i*i<=n; i++)
		{
			w.push_back(i);
			if ((n/i)!=i)
				w.push_back(n/i);
		}
		sort(w.begin(), w.end());
		for (ll i : w)
			dp.push_back(i-1);
		for (ll i=1; (i+1)*(i+1)<=n; i++)
		{
			if (dp[i]==dp[i-1])
				continue;
			for (int j=(int)w.size()-1; w[j]>=(i+1)*(i+1); j--)
				dp[j]-=dp[gdz(w[j]/(i+1))]-dp[i-1];
		}
		return dp.back();
	}
};

long long wyn;

void brut(long long n)
{
	int lim=1000*1000;
	int sito[lim+7];
	long long ret=0;
	for (int i=1; i<=lim; i++)
		sito[i]=0;
	Primes janusz;
	janusz.pi(n);
	vector <long long> pier;
	for (int i=2; i<=lim; i++)
	{
		if (sito[i])
			continue;
		pier.push_back(i);
		long long v=i;
		v*=i;
		v*=i;
		if (v<=n)
			wyn++;
		for (int j=2*i; j<=lim; j+=i)
			sito[j]=1;
	}
	int odj=0;
	for (int i=2; i<=lim; i++)
	{
		if (sito[i])
			continue;
		long long v=i;
		v*=i;
		if (v<=n)
		{
			int bsa=0;
			int bsb=pier.size();
			int bss;
			while(bsa<bsb)
			{
				bss=(bsa+bsb)>>1;
				if (pier[bss]*pier[bss]>(n/i))
					bsb=bss;
				else
					bsa=bss+1;
			}
			odj++;
			wyn+=janusz.dp[janusz.gdz(n/i)]-odj;
		}
	}
}

int main()
{
	long long n;
	scanf("%lld", &n);
	brut(n);
	printf("%lld\n", wyn);
	return 0;
}
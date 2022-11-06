#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

long long powermod(long long x, long long y, long long p)
{
    long long res = 1;    
 
    x = x % p; 
 
    while (y > 0)
    {

        if (y & 1)
            res = (res*x) % p;
 

        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	long long n;
	cin >> n;
	std::vector<long long> a(2*n);
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	std::map<long long, long long> M;
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i+n];
		if (a[i+n] == a[i])
			M[a[i]]++;
	}
	long long m;
	cin >> m;
	sort(a.begin(), a.end());
	std::vector<std::pair<long long, long long> > v;
	for (long long i = 0; i < 2*n; )
	{
		long long temp = i;
		while(temp < 2*n && a[temp] == a[i])
			temp++;
		v.pb(mp(temp - i, M[a[i]]));
		i = temp;
	}
	sort(v.begin(), v.end());
	long long siz = v[v.size()-1].first;
	std::vector<long long> fact(siz+1);
	fact[0] = 1;
	for (long long i = 1; i <= siz; ++i)
	{
		if(i&1)
		{
			fact[i] = (fact[i-1]*i)%m;
		}
		else
		{
			fact[i] = (fact[i-1]*(i/2))%m;
		}
	}
	long long res = 1;
	long long powerof2;
	for (long long i = 0; i < v.size(); ++i)
	{
		powerof2 = (v[i].first/2) - v[i].second;
		res = (((res * fact[v[i].first])%m) * powermod(2, powerof2, m))%m;
	}
	cout << res;
}
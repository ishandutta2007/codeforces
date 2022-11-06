#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
const int N = 100000;
int lowestdivisor[N+1];
std::vector<int> primes;
std::vector<int> factors;
std::vector<int> multiple(N+1, 0);
void preset(int n) {
	int siz = 0;
	memset(lowestdivisor, 0, n);
	for (int i = 2; i <= n; ++i)
	{
		if(lowestdivisor[i] == 0) {
			primes.pb(i);
			siz++;
			lowestdivisor[i] = i;
		}
	    for (int j=0; j < siz && primes[j] <= lowestdivisor[i] && i * primes[j] <= n; ++j)
			lowestdivisor[i * primes[j]] = primes[j];
	}
}

void divisors(int n) {
	factors.clear();
	if(n == 1)
		factors.pb(1);
	int lp = lowestdivisor[n];
	while(n > 1) {
		factors.pb(lp);
		while(lp == lowestdivisor[n]) {
			n /= lp;
		}
		lp = lowestdivisor[n];
	}
//	return c;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	preset(N);
	int n;
	cin>>n;
	int a[100000];
	for (int o = 0; o < n; ++o) { cin >> a[o]; }
	int dp[100000] = {0};
	int M = 0;
	for (int i = 0; i < n; ++i)
	{
		divisors(a[i]);
		int m = 0;
		for(auto i : factors){
			m = max(multiple[i]+1, m);
		}
		for (auto i : factors)
		{
			multiple[i] = m;
		}
		M = max(m, M);
	}
	cout<<M;
}
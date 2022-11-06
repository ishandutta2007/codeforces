#include <bits/stdc++.h>
#define pb emplace_back
#define int long long
#define mp make_pair

using namespace std;

bool found(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	return gcd(b % a, a);
}

pair<int, int> getans(int n, int p1, int p2)
{
	int num = 2ll * (n + 1ll) + p1 * p2 - 2ll * (p1 + p2);
	int den = 2ll * (p1) * (p2);
	int g = gcd(num, den);
	num /= g;
	den /= g;
	return {num, den};
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
	I_O;
	#else
	#define print(...) 0
	#endif
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int prprime = n;
		bool f = false;
		while(!f) {
			if(found(prprime))
				f = true;
			else
				prprime--;
		}
		int peprime = n+1;
		f = false;
		while(!f) {
			if(found(peprime))
				f = true;
			else
				peprime++;
		}
		auto ans = getans(n, prprime, peprime);
		cout << ans.first << "/" << ans.second << "\n";
	}
}
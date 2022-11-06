#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n, m;
	cin >> n >> m;
	std::vector<ll> a(n);
	std::vector<ll> b(n);
	std::vector<ll> sizred(n);
	ll total = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		sizred[i] = a[i] - b[i];
		total += a[i];
	}
	int i = 0;
	sort(sizred.rbegin(), sizred.rend());
	while(i < n && total > m) {
		total -= sizred[i++];
	}
	if(total <= m)
		cout << i;
	else
		cout << -1;
}
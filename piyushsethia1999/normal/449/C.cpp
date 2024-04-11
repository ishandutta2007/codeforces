#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;



int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<std::vector<int> > primes;
	std::vector<int> vis(n + 1, -1);
	int in = 0;
	for (int i = 2; i <= n; ++i)
		if (vis[i] == -1) {
			primes.pb(std::vector<int>());
			for (int j = i; j <= n; j += i)
				vis[j] = in;
			in++;
		}
	for (int i = 2; i <= n; ++i)
		primes[vis[i]].pb(i);
	std::vector<pair<int, int> > v;
	reverse(primes.begin(), primes.end());
	for (int i = 0; i + 1 < primes.size(); ++i)
	{
		if (primes[i].size() == 1) continue;
		else if (primes[i].size() & 1) {
			v.pb(primes[i][0], primes[i][2]);
			primes[primes.size() - 1].pb(primes[i][1]);
			for (int j = 3; j < primes[i].size(); j += 2)
				v.pb(primes[i][j], primes[i][j + 1]);
		}
		else {
			for (int j = 0; j < primes[i].size(); j += 2)
				v.pb(primes[i][j], primes[i][j + 1]);
		}
	}
	if (primes.size() >= 1 && primes[primes.size() - 1].size() & 1) primes[primes.size() - 1].pop_back();
	if (primes.size() >= 1)
		for (int i = primes.size() - 1, j = 0; j < primes[primes.size() - 1].size(); j += 2)
			v.pb(primes[i][j], primes[i][j + 1]);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].first << " " << v[i].second << "\n";
}
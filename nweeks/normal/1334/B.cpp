#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int solve()
{
	int N;
	ll x;
	cin >> N >> x;
	vector<ll> savings(N);
	for (auto &v : savings) cin >> v;
	sort(savings.rbegin(), savings.rend());
	int ans(0);
	ll cumu(0);
	for (int i(0); i < N; ++i)
	{
		cumu+=savings[i];
		if (cumu >= x * (i+1))
			ans = i+1;
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}
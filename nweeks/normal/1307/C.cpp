#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

vector<ll> cnt[26];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;

	int n = s.size();
	for (int i(0); i < 26; ++i)
		cnt[i].resize(n);

	for (int i(0); i < n; ++i)
		cnt[s[i]-'a'][i]++;
	for (int i(25); i >= 0; --i)
		for (int j(n-2); j >= 0; --j)
			cnt[i][j] += cnt[i][j+1];

	ll ans(0);
	for (int i(0); i < 26; ++i)
		ans = max(ans, cnt[i][0]);
	for (int i(0); i < 26; ++i)
		for (int j(0); j < 26; ++j)
		{
			ll c(0);
			for (int k(0); k < n-1; ++k)
				if (s[k] == 'a' + i)
					c += cnt[j][k+1];
			ans = max(c, ans);
		}
	cout << ans << endl;
}
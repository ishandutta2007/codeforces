#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = SZ(s);
		vector<bool> changed(n);
		for (int i(1); i < n; ++i)
		{
			if (s[i] == s[i-1] and !changed[i-1])
				changed[i] = true;
			if (i > 1 and s[i] == s[i-2] and !changed[i-2])
				changed[i] = true;
		}
		int ans(0);
		for (auto v : changed)
			ans += v;
		cout << ans << '\n';
	}
}
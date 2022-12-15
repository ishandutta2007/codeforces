#include <bits/stdc++.h>
using namespace std;

map<string, int> cnt;

bool is_div(int a, string s)
{
	if (s.size()%a) return false;
	for (int i(0); i < s.size(); ++i)
		if (s[i] != s[i%a]) return false;
	return true;
}

void comp(string s)
{
	int d(2);
	while (d < s.size() and !is_div(d, s)) ++d;
	for (int j(d); j <= s.size(); j += d)
		if (is_div(j, s))
			cnt[s.substr(0, j)]++;
}

int main(void)
{
	string a, b;
	cin >> a >> b;
	if (is_div(1,a))
	{
		if (!is_div(1, b) or a[0] != b[0])
		{
			cout <<0;
			return 0;
		}
		int ans(0);
		for (int i(1); i <= min(a.size(),b.size());++i)
			ans += (a.size()%i==0 and b.size()%i==0);
		cout << ans << endl;
		return 0;
	}

	comp(a), comp(b);
	int ans(0);
	for (auto e : cnt)
		if (e.second == 2) ans++;
	cout<<ans<<endl;

}
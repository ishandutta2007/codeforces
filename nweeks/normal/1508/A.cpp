#include <bits/stdc++.h>
#define int long long
using namespace std;

string solve()
{
	int n;
	cin >> n;
	string s[3];
	for (int i(0); i < 3; ++i) cin >> s[i];
	vector<array<int, 2>> nbOcc(3, {0, 0});
	for (int i(0); i < 3; ++i)
		for (auto c : s[i])
			nbOcc[i][c-'0']++;
	for (int i(0); i < 3; ++i)
		for (int j(i+1); j < 3; ++j)
			for (int car(0); car < 2; ++car)
				if (nbOcc[i][car] >= n and nbOcc[j][car] >= n)
				{
					string ret = "";
					int posI(0), posJ(0);
					for (int z(0); z < n; ++z)
					{
						while (s[i][posI] != car + '0')
							ret += s[i][posI++];
						while (s[j][posJ] != car + '0')
							ret += s[j][posJ++];
						ret += char(car + '0');
						posI++, posJ++;
					}
					while (posI < 2 * n) ret += s[i][posI++];
					while (posJ < 2 * n) ret += s[j][posJ++];
					assert(ret.size() <= 3 * n);
					return ret;
				}
	assert(false);
	return "";
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}
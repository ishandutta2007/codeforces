#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

vector<int> calcZ(const string &s)
{
	vector<int> z(SZ(s));
	z[0] = SZ(s);
	int l=-1, r=-1;
	for (int i(1); i < SZ(s); ++i)
	{
		if (i < r) z[i] = min(r-i, z[i-l]);
		while (z[i] + i < SZ(s) and s[i+z[i]] == s[z[i]]) ++z[i];
		if (i + z[i] > r)
			l = i, r = z[i] + i;
	}
	return z;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;

	auto z = calcZ(s);
	vector<int> prefixBest(SZ(s));
	for (int i(1); i < SZ(s); ++i)
		prefixBest[i] = max(prefixBest[i-1], z[i]);
	for (int i(SZ(s)-1); i > 0; --i)
		if (z[SZ(s) - i] >= i and prefixBest[SZ(s)-i-1] >= i)
		{
			cout << s.substr(0, i) << endl;
			return 0;
		}
	cout << "Just a legend" << endl;
}
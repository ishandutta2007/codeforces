#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

string solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n';
}

string solve(void)
{
	int len, nb_chaines;
	string s;
	cin >> len >> nb_chaines >> s;
	vector<int> occ(26);
	for (auto c :s)
		occ[c-'a']++;
	string ret = "";
	int first_carac(0);
	while (first_carac < 26 and !occ[first_carac])
		++first_carac;
	if (occ[first_carac] < nb_chaines)
	{
		int tot(occ[first_carac]);
		int ans(first_carac);
		while (tot < nb_chaines)
			tot += occ[++ans];
		ret += (ans + 'a');
		return ret;
	}
	occ[first_carac] -= nb_chaines;
	ret += (first_carac + 'a');
	if (nb_chaines == len)
		return ret;
	len -= nb_chaines;
	while (!occ[first_carac])
		++first_carac;

	if (occ[first_carac] == len)
	{
		int nb = len/nb_chaines + !!(len%nb_chaines);
		while (nb--)
			ret += (first_carac + 'a');
		return ret;
	}
	for (int i(first_carac); i < 26; ++i)
		while (occ[i] > 0)
		{
			ret += (i + 'a');
			occ[i]--;
		}
	return ret;
}
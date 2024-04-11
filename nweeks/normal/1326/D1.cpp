#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

/*vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}*/

vector<int> calc_z(const string &s)
{
	int n = SZ(s);
	vector<int> z(n);
	int l(0), r(0);
	for (int i(0); i < n; ++i)
	{
		if (i <= r)
			z[i] = min(r-i+1, z[i-l]);
		while (i + z[i] < n and s[z[i]] == s[i+z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}


string get_ans(const string &s)
{
	int n = SZ(s);

	vector<vector<bool> > is_palin(n);
	for (int i(0); i < n; ++i)
		is_palin[i].resize(n);
	
	for (int i(0); i < n; ++i)
		is_palin[i][i] = true;
	for (int i(0); i +1  <n; ++i)
		is_palin[i][i+1] = s[i]==s[i+1];
	for (int d(3); d <= n; ++d)
		for (int i(0); i + d <= n; ++i)
			is_palin[i][i+d-1] = (s[i] == s[i+d-1] and is_palin[i+1][i+d-2]);
	
	int ans(0), l(0), r(0);
	for (int len_b(0); 2*len_b <= n; ++len_b)
	{
		bool can(true);
		for (int i(0); i < len_b; ++i)
			if (s[i] != s[n-1-i])
				can = false;
		if (!can) continue;

		for (int j(n-len_b-1); j >= len_b; --j)
		{
			if (is_palin[len_b][j] and len_b + j+1 > ans)
			{
				ans = len_b + j + 1;
				l = j;
				r = len_b;
			}
		}
	}

	string ret = "";
	for (int i(0); i <= l; ++i)
		ret += s[i];
	for (int i(0); i < r; ++i)
		ret += s[n-r+i];

	return ret;
}

string solve(void)
{
	string s;
	cin >> s;
	int n = SZ(s);

	bool is_pal(true);
	for (int i(0); i < n; ++i)
		if (s[n-1-i] != s[i])
			is_pal = false;
	if (is_pal)
		return s;
	
	string ans1= get_ans(s);
	reverse(s.begin(), s.end());
	string ans2 = get_ans(s);
	if (SZ(ans1) > SZ(ans2))
		return ans1;
	else
		return ans2;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';;
}
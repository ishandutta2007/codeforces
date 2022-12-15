#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

string get_ans(const string &s)
{
	int n = SZ(s);
	
	vector<int> valid(n, 0);
	
	for (int i(0); i < n; ++i)
	{
		if (s[i] != s[n-1-i])
		{
			valid[i] = 0;
			break;
		}
		valid[i] = 1;
	}
	for (int i(0); i < n; ++i)
	{
		valid[i] = (valid[i] ? i : -1);
		if (i)
			valid[i] = max(valid[i], valid[i-1]);
	}

	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}

	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	/*cout << "-----------\n";
	for (int i(0); i < n; ++i)
		cout << s[i] << ' ';
	cout << endl;
	for (int i(0); i < n; ++i)
		cout << valid[i] << ' ';
	cout << endl;
	for (int i(0); i < n; ++i)
		cout << d1[i] << ' ';
	cout << endl;
	for (int i(0); i < n; ++i)
		cout << d2[i] << ' ';
	cout << endl;
	cout << "--------------\n";*/
	int ans(0), len_ans(0), r(0);
	for (int i(0); i < (1+n)/2; ++i)
	{
		if (i - d1[i] <= valid[i])
		{
			if (ans < 2*i+1)
				ans = 2*i+1, len_ans = valid[i]+1, r = i + (i-valid[i]);
		}
		if (i - d2[i]-1 <= valid[i])
		{
			if (ans < 2*i)
				ans = 2*i, len_ans = valid[i] + 1, r = i + (i-valid[i]-1);
		}
	}
	string ret = "";
	for (int i(0); i < r; ++i)
		ret += s[i];
	for (int i(0); i < len_ans; ++i)
		ret += s[n-len_ans+i];

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
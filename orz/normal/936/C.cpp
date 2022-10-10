#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#define gl getline
#define X first
#define Y second
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vei;
typedef vector<vei> vvei;
typedef vector<bool> veb;
typedef vector<veb> vveb;

template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p)
{
	fin >> p.X >> p.Y;
	return fin;
}
template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}

string sht(const string& s, const int& k, vei& v)
{
	int n = sz(s);
	v.push_back(k);
	string ans = s;
	for (int i = 0; i < k; ++i)
		ans[i] = s[n - 1 - i];
	for (int i = k; i < n; ++i)
		ans[i] = s[i - k];
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s, t;
	getline(cin, s);
	getline(cin, s);
	getline(cin, t);
	string ss = s, tt = t;
	sort(ss.begin(), ss.end());
	sort(tt.begin(), tt.end());
	if (ss != tt)
		cout << "-1\n";
	else
	{
		int r = 0;
		vei ans;
		bool start = true;
		while (r < n)
		{
			if (start)
			{
				int f;
				char a = t[r];
				for (f = r; s[f] != a; ++f);
				s = sht(s, n - f, ans);
				s = sht(s, f + 1, ans);
				s = sht(s, n - f - 1, ans);
				start = false;
				++r;
			}
			else
			{
				int f;
				char a = t[r];
				for (f = n - 1 - r; s[f] != a; --f);
				s = sht(s, n - f - 1, ans);
				s = sht(s, 1, ans);
				start = true;
				++r;
			}
		}
		if (start)
			s = sht(s, n, ans);
		cout << sz(ans) << '\n';
		for (int i = 0; i < sz(ans); ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		
		//cout << '\n' << s << '\n' << t << '\n';
	}
	return 0;
}
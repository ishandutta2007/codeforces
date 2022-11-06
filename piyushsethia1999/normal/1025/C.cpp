#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;
set<int> s;
void getdivisor(int a) {
	for (int i = 2; i * i <= a; ++i)
	{
		if (a % i == 0) {
			s.insert(i);
			while (a % i == 0) {
				a /= i;
			}
		}
	}
	if (a > 1)
		s.insert(a);
}
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	string s; cin >> s;
	std::vector<int> a(s.size(), 0);
	int pre = 0;
	int post = 0;
	a[0] = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] != s[i - 1])
			a[i] = a[i - 1] + 1;
		else
			a[i] = 1;
	}
	for (pre = 1; pre < s.size(); ++pre)
	{
		if (s[pre] == s[pre - 1])
			break;
	}
	post = 1;
	int siz = s.size();
	for (post = 1; post < s.size(); ++post)
	{
		if (s[siz - 1 - post] == s[siz - post])
			break;
	}
	int ma = 0;
	for (int i = 0; i < siz; ++i)
	{
		ma = max(ma, a[i]);
	}
	print(pre, post, a);
	if (s[0] != s[siz - 1])
		ma = max(ma, pre + post);
	if (ma > siz)
		ma = siz;
	cout << ma;
}
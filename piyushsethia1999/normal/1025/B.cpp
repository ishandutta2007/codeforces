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
	int n; cin >> n;
	vector<int> a(n), b(n); for (int o = 0; o < n; o++) { cin >> a[o] >> b[o]; }
	getdivisor(a[0]);
	getdivisor(b[0]);
	set<int> s1;
	for (int i = 1; i < n; ++i)
	{
		for (int d : s)
		{
			if (a[i] % d == 0)
				s1.insert(d);
			else if (b[i] % d == 0)
				s1.insert(d);
		}
		s = s1;
		s1.clear();
	}
	if (s.size() > 0)
		cout << *(s.begin());
	else
		cout << -1;
}
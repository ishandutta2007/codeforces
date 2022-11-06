#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	string s; cin >> s;
	int a[k] = {0};
	for (int i = 0; i < s.size(); ++i)
		a[s[i] - 'A']++;
	int m = 100000000;
	for (int i = 0; i < k; ++i)
		m = min(m, a[i]);
	cout << m * k;
}
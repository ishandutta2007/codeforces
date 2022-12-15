#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &v : a) cin >> v;
	for (auto &v : b) cin >> v;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i(0); i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
	for (int i(0); i < n; ++i)
		cout << b[i] << ' ';
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}
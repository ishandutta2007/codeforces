#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	int n;
	ll p, q, r;
	cin >> n >> p >> q >> r;
	vector<ll> a(n), a3(n), a2(n), a1(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	a3[n - 1] = r * a[n - 1];
	a2[n - 1] = q * a[n - 1] + a3[n - 1];
	a1[n - 1] = p * a[n - 1] + a2[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		a3[i] = max(a3[i + 1], r * a[i]);
		a2[i] = max(a2[i + 1], q * a[i] + a3[i]);
		a1[i] = max(a1[i + 1], p * a[i] + a2[i]);
	}
	cout << *(a1.begin());
	return 0;
}
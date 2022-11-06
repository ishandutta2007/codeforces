#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	cout << ((2 * n + k - 1) / k + (5 * n + k - 1) / k + (8 * n + k - 1) / k );
}
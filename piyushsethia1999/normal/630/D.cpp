#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	n *= (n + 1ll);
	n /= 2l;
	n *= 6ll;
	n++;
	cout << n;
}
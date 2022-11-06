#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n, m;
	cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.rbegin(), a.rend());
int i, s = 0;
for ( i = 0; i < n; ++i) {
	s += a[i];
	if (s >= m)break; 
}
	cout << i + 1;
}
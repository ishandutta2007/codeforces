#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int to = abs(z - x) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
	int ti = t1 * abs(x - y);
	if (ti < to)
		cout << "NO";
	else
		cout << "YES";
}
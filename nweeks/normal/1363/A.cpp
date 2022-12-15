#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
	int n, x;
	cin >> n >> x;
	int nb[2] = {0, 0};
	for (int i(0); i < n; ++i)
	{
		int v;
		cin >> v;
		nb[v%2]++;
	}
	bool can(false);
	for (int takeOdd(1); takeOdd <= x; takeOdd += 2)
		can = can or (takeOdd <= nb[1] and x - takeOdd <= nb[0]);
	if (can) cout << "Yes\n";
		else cout << "No\n";
}
}
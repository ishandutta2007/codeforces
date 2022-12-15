#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

bool solve()
{
	int n;
	cin >> n;
	int cum_p(0), cum_c(0);
	vector<pair<int, int> > a(n);
	for (auto &[x,y] : a)
		cin >> x >> y;
	for (auto [p, c] : a)
	{
		p -= cum_p;
		c -= cum_c;
		if (p < c or p < 0 or c < 0)
			return false;
		cum_p+=p;
		cum_c+=c;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << (solve() ? "YES" : "NO") << '\n';
}
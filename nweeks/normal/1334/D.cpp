#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	ll n, l, r;
	cin >> n >> l >> r;
	
	if (l == n*(n-1)+1)
	{
		cout << 1 << '\n';
		return ;
	}
	ll vu(0);
	ll tour(1);
	while (vu + 2*(n-tour) < l)
	{
		vu += 2*(n-tour);
		++tour;
	}
	
	while (vu < r)
	{
		if (tour == n)
		{
			cout << 1;
			break;
		}
		for (int i(tour+1); i <= n and vu < r; ++i)
		{
			if (vu >= l-1)
				cout << tour << ' ';
			++vu;
			if (vu >= l-1 and vu < r)
				cout << i << ' ';
			++vu;
		}
		++tour;
	}
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
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

ll solve(void)
{
	ll a, b;
	cin >> a >> b;
	if (a%b)
		return b - (a%b);
	else
		return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		cout << solve() << '\n';
}
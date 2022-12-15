#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

ll solve(void)
{
	ll A, B;

	cin >> A >> B;
	ll ret(0);
	for (ll x(10); x-1 <= B; x *= 10)
		ret += A;

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}
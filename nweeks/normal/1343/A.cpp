#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '

typedef	long long ll;

int solve(int testcase);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	for (int _t(1); _t <= __t; _t++)
		cout << solve(_t) << '\n';
}

int solve(int testcase)
{
	ll n;
	cin>>n;
	ll k(2);
	while (1)
	{
		if (n%((1LL<<k)-1)==0)
			return n/((1LL<<k)-1);
		++k;
	}
	return testcase;
}
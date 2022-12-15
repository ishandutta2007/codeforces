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
		solve(_t);
}

int solve(int testcase)
{
	int n;
	cin >> n;
	n /= 2;
	if (n%2)
	{
		pnl("NO");
		return 0;
	}
	else
	{
		pnl("YES");
		FOR(i,0,n) pns(4*(i+1));
		FOR(i,0,n)
		{
			int print = 4*(i+1) + (i%2?-1:1);
			pns(print);
		}
		cout<<endl;
	}

	return testcase;
}
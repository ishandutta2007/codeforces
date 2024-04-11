#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

ll calc(int d, int m, int p)
{
	if (d==1)
		return 1%m;
	while ((1<<p) > d)
		p--;
	ll higher = d - (1<<p) + 1;

	return (higher + calc((1<<p)-1, m, p) * (higher+1)%m)%m;
}

ll solve(int d, ll m)
{
	int p = 0;
	while ((1<<p) < d)
		++p;
	
	return calc(d,m,p);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int d, m;
		cin >> d >> m;
		cout << solve(d,m) << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;
	int m = (n+1)/2;
	if (m == n-m) ++m;
	if (n<=2)
		cout << 0 << '\n';
	else
		cout << n-m << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve()
{
	ll n, k;
	cin >> n >> k;
	if (n < k*k)
	{
		cout << "NO\n";
		return ;
	}
	n -= k*k;
	if (n%2==0)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}
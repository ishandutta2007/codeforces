#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	ll n, m;

	cin >> n >> m;
	
	ll block_c = min(m+1, n-m);
	if (block_c == 0)
	{
		cout << (n*(n+1))/2 << '\n';
		return ;
	}
	
	ll block_sz = (n-m)/block_c;
	ll cnt  = block_c *block_sz;
	ll need = n-m-cnt;

	ll ans = (n*(n+1))/2 - need * ((block_sz + 1) * (block_sz + 2))/2 - (block_c-need) * ((block_sz) * (block_sz+1))/2;
	cout << ans << '\n';
	
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
}
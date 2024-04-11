#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< vector<ll> > q;

int main()
{
	ll n, m, k, x, y;
	cin >> n >> m >> k >> x >> y;
	if (n == 1)
    {
        ll z = k / m;
        ll q = k % m;
        ll ans = z;
        if (q >= y)
            ans++;
        if (q != 0)
            z++;
        cout << z << " " << k / m << " " << ans;
        return 0;
    }
    x--;
    y--;
	ll w = k / m;
	ll f = w / (2 * n - 2);
	q.assign(n, vector<ll>(m, (ll)(0)));
	for (int i = 1; i + 1 < n; i++)
        for (int j = 0; j < m; j++)
            q[i][j] = 2 * f;
    for (int j = 0; j < m; j++)
        q[0][j] = f, q[n - 1][j] = f;
    k -= f * (2 * n - 2) * m;
    int dx = 1;
    int i = 0;
    while (k > 0)
    {
        for (int j = 0; j < m && k > 0; j++)
            q[i][j]++, k--;
        i += dx;
        if (i == n)
            i = n - 2, dx = -1;
        if (i < 0)
            i = 1, dx = 1;
    }
    ll maxx = 0, minn = 2e18;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            maxx = max(maxx, q[i][j]), minn = min(minn, q[i][j]);
    cout << maxx << " " << minn << " " << q[x][y];
	return 0;
}
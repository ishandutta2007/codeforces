#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e5 + 10, maxm = 5e6 + 10;
LL a[maxm], p[maxm], s[maxn];
LL n, m;

LL solve(LL k){
	p[m] = min(a[m], k * n - k * (k - 1) / 2 * m);
	for(int i = m - 1; i > 0; i--)
		p[i] = min(a[i], p[i + 1] - k);
	if(p[1] <= 0)
		return 0;
	LL ret = p[1];
	s[1] = p[1];
	//calc spaces
	LL val1 = (p[1] - k * (k - 1) / 2 * m) / k;
	LL val2 = p[1] + (k - 1) * (k - 2) / 2 * m - (k - 1) * n;
	if(val1 <= 0 or val1 < val2)
		return 0;
	LL spaces = n - max(1LL, val2) - k + 1;
	for(LL i = 2; i <= m; i++){
		s[i] = s[i - 1] + min(p[i] - s[i - 1], spaces - k * (m - i));
		ret += s[i];
		spaces -= min(p[i] - s[i - 1], spaces - k * (m - i));
	}
	//cout << k << " -> " << val1 << ' ' << val2 << ' '  << n - max(1LL, val2) - m + 1 << ' ' << ret << endl;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	LL ans = 0;
	for(int days = 1; days <= n / m; days++){
		ans = max(ans, solve(days));
		//cout << days << " -> " << solve(days) << endl;
	}
	cout << ans << endl;
	return 0;
}
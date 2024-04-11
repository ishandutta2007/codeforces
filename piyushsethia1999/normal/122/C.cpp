#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int MAXN = 1e10;
std::vector<int> v;

int calc(int l) {
	if (l <= 4)
		return 4 * l;
	int ans = 4 * 4;
	for (int i = 1; i < v.size(); ++i)
		ans += (v[i] * max(0ll, min(v[i], l) - v[i - 1]));
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	priority_queue<int, std::vector<int>, greater<int> > pq;
	pq.push(4);
	pq.push(7);
	while (!pq.empty()) {
		int o = pq.top();
		pq.pop();
		v.pb(o);
		if (o * 10ll + 7ll <= MAXN) {
			pq.push(o * 10ll + 7ll);
			pq.push(o * 10ll + 4ll);
		} else if(o * 10ll + 4ll <= MAXN) {
			pq.push(o * 10ll + 4ll);
		}
	}
	int l; cin >> l;
	int r; cin >> r;
	cout << (calc(r) - calc(l - 1));
}
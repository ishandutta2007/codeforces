//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10;
int a[maxn],
	b[maxn],
	cnt[maxn],
	n, m;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int val = n / m;
	for (int i = 0; i < m; i++)
		cnt[i] -= val;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		a[i] = b[i] % m;
		cnt[a[i]]++;
	}
	for (int i = 0; i < m; i++)
		if (cnt[i] < 0)
			s.insert(i);
	LL ans = 0;
	for (int i = 0; i < n; i++)
		if (cnt[a[i]] > 0) {
			auto it = s.lower_bound(a[i]);
			if (it == s.end())
				it = s.begin();
			int curval = ((*it) - a[i] + m + m) % m;
			ans += curval;
			b[i] += curval;
			cnt[a[i]]--;
			cnt[*it]++;
			if (cnt[*it] == 0)
				s.erase(it);
		}
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	cout << endl;
	return 0;
}
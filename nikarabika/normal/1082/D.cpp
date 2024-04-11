//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define L first
#define R second

const int maxn = 1e5 + 10;
vector<int> yek;
vector<pii> more,
	e;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			yek.PB(i);
		else
			more.PB({i, x});
	}
	while (sz(yek) < 2) {
		yek.PB(more.back().L);
		more.pop_back();
	}
	if (sz(more) == 0)
		return cout << "NO\n", 0;
	int ans = sz(more) + 1;
	e.PB({more[0].L, yek.back()});
	more[0].R--;
	yek.pop_back();
	if (more.back().R == 0)
		return cout << "NO\n", 0;
	e.PB({more.back().L, yek.back()});
	more.back().R--;
	yek.pop_back();
	for (int i = 0; i + 1 < sz(more); i++) {
		e.PB({more[i].L, more[i + 1].L});
		more[i].R--;
		more[i + 1].R--;
	}
	for (auto v : yek) {
		while (sz(more) and more.back().R == 0)
			more.pop_back();
		if (sz(more) == 0)
			return cout << "NO\n", 0;
		e.PB({v, more.back().L});
		more.back().R--;
	}
	cout << "YES " << ans << '\n';
	cout << sz(e) << '\n';
	for (auto ed : e)
		cout << ed.L + 1 << ' ' << ed.R + 1 << '\n';
	return 0;
}
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

const int maxn = 2750131 + 100;
int isp[maxn],
	fir[maxn],
	prmcnt = 1;
vector<int> ans;
multiset<int, greater<int> > s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(isp, -1, sizeof isp);
	isp[0] = isp[1] = false;
	for (int i = 0; i < maxn; i++)
		if (!~isp[i]) {
			for (LL j = 1LL * i * i; j < maxn; j += i)
				isp[j] = -2, fir[j] = !fir[j] ? j / i : fir[j];
			isp[i] = prmcnt++;
		}
	int n;
	cin >> n;
	for (int i = 0; i < n + n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	while (sz(s)) {
		assert(sz(ans) < n);
		int x = *s.begin();
		s.erase(s.begin());
		if (isp[x] == -2) {
			ans.PB(x);
			s.erase(s.find(fir[x]));
		}
		else {
			ans.PB(isp[x]);
			s.erase(s.find(isp[x]));
		}
	}
	for (auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}
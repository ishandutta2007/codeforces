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

const int maxd = 5e5 + 100;
int poscnt[maxd],
	negcnt[maxd];

pii get(string &s) {
	int mn = 0,
		sum = 0;
	for (auto c : s) {
		if (c == '(')
			sum++;
		else
			sum--;
		smin(mn, sum);
	}
	return MP(sum, mn);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pii stat = get(s);
		if (stat.L < 0 and -stat.L + stat.R >= 0)
			negcnt[-stat.L]++;
		else if (stat.L > 0 and stat.R >= 0)
			poscnt[+stat.L]++;
		else if (stat.R >= 0) {
			ans += poscnt[0] & 1;
			poscnt[0]++;
		}
	}
	for (int i = 1; i < maxd; i++)
		ans += min(poscnt[i], negcnt[i]);
	cout << ans << endl;
	return 0;
}
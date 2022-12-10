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

const int maxn = 1e5 + 10;
LL len[maxn],
   n, s;
vector<int> vec[maxn];

LL getmn(LL rcnt, LL vcnt, LL rooth, LL deg) {
	if (deg == 1) {
		LL mn = vcnt / rcnt;
		LL mx = mn + 1;
		LL mncnt = rcnt - (vcnt % rcnt);
		LL mxcnt = vcnt % rcnt;
		return (mncnt * mn * (mn + 1) + mxcnt * mx * (mx + 1)) / 2;
	}
	LL sum = 0;
	LL siz = rcnt;
	while (vcnt) {
		sum += min(vcnt, siz) * rooth;
		vcnt -= min(vcnt, siz);
		siz *= deg;
		rooth++;
	}
	return sum;
}

bool check(LL o) {
	return getmn(1, n, 1, o) <= s;
	LL sum = 0;
	LL rem = n;
	LL siz = 1;
	LL h = 1;
	while (rem) {
		sum += min(siz, rem) * h;
		h++;
		rem -= min(siz, rem);
		siz *= o;
	}
	return sum <= s;
}

void create(LL n, LL deg) {
	len[0] = 1;
	LL curn = n - 1;
	LL curs = s - 1;
	for (int i = 1; curn; i++) {
		len[i] = 1;
		while (getmn(len[i], curn, i + 1, deg) > curs)
			len[i]++;
		curn -= len[i];
		curs -= len[i] * (i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	if (s < 2 * n - 1 or s > n * (n + 1) / 2)
		return cout << "No" << endl, 0;
	LL lo = 0,
	   hi = n;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << "Yes\n";
	create(n, hi);
	int last = 1;
	vec[0].PB(1);
	for (int i = 1; i < n; i++) {
		int ptr = 0;
		int rem = hi;
		for (int j = 0; j < len[i]; j++) {
			vec[i].PB(++last);
			cout << vec[i - 1][ptr] << ' ';
			rem--;
			if (!rem) {
				rem = hi;
				ptr++;
			}
		}
	}
	cout << endl;
	return 0;
}
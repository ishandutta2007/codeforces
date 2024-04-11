#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(1e6) + 10;

int n, k;
char s[maxn];

int sa[maxn], rnk[maxn], tmp[maxn];
int lcp[maxn];

void build() {
	iota(sa, sa+n, 0);
	rep(i, n) rnk[i] = s[i];
	rnk[n] = -1;
	sort(sa, sa+n, [&](const int& a, const int& b) { return s[a] < s[b]; });

	for (int l=1; l<n; l*=2) {
		for (int i=0, ni; i<n; i=ni) {
			for (ni=i; ni<n && rnk[sa[i]] == rnk[sa[ni]]; ++ni);

			auto cmp = [&](const int& a, const int& b) {
				if (rnk[a] != rnk[b]) return rnk[a] < rnk[b];
				return rnk[l+a] < rnk[l+b];
			};

			sort(sa+i, sa+ni, cmp);

			tmp[sa[i]] = (i ? (tmp[sa[i-1]]+1) : 0);
			for (int j=i+1; j<ni; ++j) {
				tmp[sa[j]] = tmp[sa[j-1]] + cmp(sa[j-1], sa[j]);
			}
		}

		copy(tmp, tmp+n, rnk);
	}

	if (n == 1) {
		lcp[0] = 0;
		return;
	}

	int m = 0;

	rep(i, n) {
		if (m) --m;
		if (rnk[i] == n-1) continue;
		int j = sa[rnk[i]+1];
		while (s[i+m] == s[j+m]) ++m;
		lcp[rnk[i]] = m;
	}

	lcp[n-1] = 0;
}

int u[maxn], un;

const int inf = int(1e9) + 10;

int pow2_safe(int x) {
	if (x >= 30) return inf;
	return 1<<x;
}

bool ok(int i) {
	int v = 0;
	int ui = u[i];
	rep(j, k) {
		v = (v*2) + (s[ui+j] - '0');
		if (v >= inf) return false;
	}
	return v == i;
}

void print(int x) {
	rep(i, max(0, k-30)) cout << '0';
	bool s = 0;
	for (int i=29; 0<=i; --i) {
		bool b = 1&(x>>i);
		s = s || b || (i < k);
		if (s) cout << char('0' + b);
	}
	cout << '\n';
}

int main()
{
	cppio();
	int tc; cin >> tc;
rep(tci, tc) {
	cin >> n >> k >> s;
	rep(i, n) s[i] ^= 1;
	build();

	un = 0;
	for (int i=0; i<n; ++i) {
		if (lcp[i] >= k) continue;
		if (sa[i]+k > n) continue;
		u[un++] = sa[i];
	}

	int l = -1, r = min(pow2_safe(k), un);
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (ok(mid)) l = mid;
		else r = mid;
	}

	if (r == pow2_safe(k)) {
		cout << "NO\n"; continue;
	}

	cout << "YES\n";
	print(r);
}
	return 0;
}
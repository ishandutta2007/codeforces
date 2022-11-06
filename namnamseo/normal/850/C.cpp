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

const int maxn = 100 + 10;

int n;
int a[maxn];

ll ps[maxn * 1000]; int pn;

void Decom(ll v) {
	for (ll i=2; v>1 && i*i <= v;++i) {
		if (v%i) continue;
		ps[pn++] = i;
		while (v%i == 0) v/=i;
	}
	if (v > 1) ps[pn++] = v;
}

using U = unsigned int32_t;
unordered_map<int,int> dp;
int F(U m) {
	if (!m) return 0;
	auto it = dp.find(m);
	if (it != dp.end()) return it->y;

	int b_hi = 30;
	while (!(1&(m >> (b_hi-1)))) --b_hi;
	vector<int> nxt; nxt.reserve(b_hi);

	rrep(i, b_hi) {
		U nm = ((m >> (i)) | (m & ((1 << (i-1))-1)));
		nxt.push_back(F(nm));
	}
	sort(nxt.begin(), nxt.end());
	nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
	for (int i=0;;++i) {
		if (i == int(nxt.size()) || nxt[i] != i) {
			return dp[m] = i;
		}
	}
	return -1;
}

int Solve(int p) {
	U m = 0;
	rep(i, n) {
		int t = a[i], c = 0;
		while (t%p == 0) {
			++c;
			t /= p;
		}
		if (c) m |= (1llu << (c-1));
	}

	return F(m);
}

int main()
{
	cppio();
	dp.reserve(10000);

	cin >> n;
	rep(i, n) cin >> a[i];

	rep(i, n) Decom(a[i]);
	sort(ps, ps+pn); pn = unique(ps, ps+pn)-ps;

	int ans = 0;
	rep(i, pn) ans ^= Solve(ps[i]);
	cout << (ans ? "Mojtaba" : "Arpa") << '\n';

	return 0;
}
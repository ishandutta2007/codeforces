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

const int maxn = int(1e5) + 10;
const ll mod = 998'244'353;

ll ipow(ll b, ll e) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}

ll fact[2*maxn];
ll finv[2*maxn];
void Build() {
	const int N = int(2e5);
	fact[0] = 1;
	for (int i=1; i<=N; ++i) fact[i] = fact[i-1]*1ll*i%mod;
	finv[N] = ipow(fact[N], mod-2);
	for (int i=N; 1<=i; --i) finv[i-1] = finv[i]*i%mod;
}

int n;
char s[maxn];

int C(int n, int r) {
	return fact[n] * finv[r] % mod * finv[n-r] % mod;
}

int H(int n, int r) {
	return C(n+r-1, r);
}

void Work() {
	cin >> n;
	cin >> (s+1);
	vector<pair<char,int>> v;
	for (int i=1; i<=n;) {
		int j = i+1;
		while (j<=n && s[i]==s[j]) ++j;
		v.emplace_back(s[i], j-i);
		i = j;
	}

	vector<int> zeros;
	zeros.pb(0);
	ll ec = 0;
	int o1 = 0;
	for (auto [c, cnt] : v) {
		if (c == '1') {
			ec += cnt/2; cnt %= 2;
			if (!cnt) continue;
			++o1; zeros.pb(0);
		} else {
			zeros.back() += cnt;
		}
	}

	int zs = accumulate(all(zeros), 0);
	cout << H(zs+1, ec) << '\n';
}

int main()
{
	cppio(); Build();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}
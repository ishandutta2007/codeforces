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

const int maxn = int(2e5) + 10;

int n;
ll a[maxn];

int M;
ll t[524288];

ll Gcd(ll a, ll b) { return b?gcd(b,a%b):a; }

ll RangeGcd(int l, int r) {
	ll ret = 0;
	for(l+=M, r+=M; l<=r; l/=2, r/=2) {
		if (l%2 == 1) ret = Gcd(ret, t[l++]);
		if (r%2 == 0) ret = Gcd(ret, t[r--]);
	}
	return ret;
}

void Work() {
	cin >> n;
	rrep(i, n) cin >> a[i];

	for (M=1; M<(n+1); M*=2);
	rrep(i, n-1) t[M+i] = abs(a[i+1] - a[i]);
	for (int i=n; i<M; ++i) t[M+i] = 0;
	for (int i=M-1; 1<=i; --i) t[i] = Gcd(t[i*2], t[i*2+1]);

	int ans = 1;

	for (int bl=1; bl<=n-1; ++bl) {
		int il = bl-1, ir=n;
		while (il+1 < ir) {
			int im = (il+ir)/2;
			if (RangeGcd(bl, im) > 1) {
				il = im;
			} else {
				ir = im;
			}
		}
		int br = il;
		ans = max(ans, br - bl + 2);
	}

	cout << ans << '\n';
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}
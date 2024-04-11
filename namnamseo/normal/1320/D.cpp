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

int n;
const int maxn = 2e5 + 10;
char t[maxn];

int pr[maxn];
int scnd[maxn];

ll p = 612317;
ll mod = 1000000123;

ll h[maxn];
ll dc[maxn];

bool cok(int a, int b, int len)
{
	return (pr[a+len-1]-pr[a-1]) == (pr[b+len-1]-pr[b-1]);
}

ll ppow[maxn];

pll gh(int a, int len)
{
	int r = a + len - 1;

	if (pr[r]-pr[a-1] == len) {
		if (len%2 == 0) return pll{len/2, 0};
		else return pll{len/2, 1};
	}

	bool f = 0;
	if (scnd[r+1]) {
		f = 1;
		--r;
	}

	int bc = dc[a] - dc[r+1];
	ll mh = (h[a] + mod - (h[r+1] * ppow[r+1-a-2*bc] % mod)) % mod;
	if (f) {
		mh += ppow[len-2*bc-1];
		mh %= mod;
	}

	return pll{bc, mh};
}

int main()
{
	cppio(); cin >> n >> (t+1);
	rrep(i, n) pr[i]=pr[i-1]+(t[i]=(t[i]=='1'));

	ppow[0] = 1;
	rrep(i, n) ppow[i] = ppow[i-1]*p%mod;

	for(int i=2; i<=n; ++i) if(t[i-1] && t[i]) scnd[i] = !scnd[i-1];

	for(int i=n; 1<=i; --i) {
		if (t[i]) {
			if (t[i+1]) {
				h[i] = h[i+2];
				dc[i] = dc[i+2] + 1;
			} else {
				h[i] = (1 + p * h[i+1]) % mod;
				dc[i] = dc[i+1];
			}
		} else {
			h[i] = h[i+1] * p % mod;
			dc[i] = dc[i+1];
		}
	}

	int q; cin >> q;
	for(;q--;) {
		int a, b, len; cin >> a >> b >> len;
		if (cok(a, b, len) && gh(a, len) == gh(b, len))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
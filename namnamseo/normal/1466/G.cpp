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

#define DBG if(0)
#define printf DBG printf

const int maxn = int(1e5) + 10;

int n, q;
char s[110];
int sn;
char t[maxn];

int k;
char buf[maxn * 10];
int bn;

const ll mod = int(1e9) + 7;

char stock[maxn * 20];
int stkn;

ll ans;

ll ipow(ll b, ll e) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}

ll bc[maxn][26];

ll Z(ll &x) { if (x >= mod) x -= mod; }

void work(char *s, int sn, char *buf, int bn,
	int lev) {
	if (!sn) return;
	if (k < lev) return;

	if (bn == 1 && lev) {
		ll ad = bc[k][buf[0]-'a'];
		if (lev) {
			ad += mod - bc[lev-1][buf[0]-'a'] * ipow(2, k-(lev-1)) % mod;
			Z(ad);
		}
		ans += ad;
		Z(ans);
		return;
	}

	/*DBG {
		cout << string(lev, '\t') << "Buf: " << string(buf, bn) << ", s:"
			<< string(s, sn) << endl;
	}*/

	for (int offset = 0; offset <= sn; ++offset) {
		int en = 0;
		int ci = offset;
		bool ok = 1;

		char *ext = stock + stkn;
		int ei = 0;

		rep(i, bn) {
			if (ci == sn) {
				ext[ei++] = buf[i];
				ci = 0;
			} else {
				if (buf[i] != s[ci]) {
					ok = 0;
					break;
				}
				++ci;
			}
		}

		if (!ok) continue;

		if (!ei) {
			ans += ipow(2, k-lev);
			Z(ans);
		} else {
			stkn += ei;

			char *ns = (lev ? (s+1) : (t));
			work(ns, 1, ext, ei, lev+1);

			stkn -= ei;
		}
	}

}

int main()
{
	cppio();
	cin >> n >> q >> s >> t;
	sn = strlen(s);

	rep(i, sn) {
		bc[0][s[i]-'a']++;
	}

	rrep(i, n) {
		rep(j, 26) {
			bc[i][j] = bc[i-1][j] * 2;
			Z(bc[i][j]);
		}
		++bc[i][t[i-1]-'a'];
		Z(bc[i][t[i-1]-'a']);
	}

for(;q--;) {
	cin >> k >> buf;
	bn = strlen(buf);
	ans = 0;

	work(s, sn, buf, bn, 0);

	cout << ans << '\n';
}

	return 0;
}
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

const int maxn = int(3e5) + 10;
const int V = int(3e5);

int n;
int a[maxn];

ll ans[maxn];

template<typename T=int>
struct Fen {
	T t[maxn];
	void upd(int p, T v) { for (; p<=V; p+=(p&(-p))) t[p] += v; }
	T s(int p) { T ret = 0; for (;p;p&=(p-1)) ret += t[p]; return ret; }
};

Fen fc; Fen<ll> fv;

void naive() {
	for (int i=1; i<=n; ++i) {
		ans[i] = ans[i-1];
		int v = a[i];
		ans[i] += fv.s(v);
		ans[i] += v * 1ll * (i - 1 - fc.s(v));

		fc.upd(v, 1);
		fv.upd(v, v);
	}
}

using pll=pair<ll,ll>;

pll operator+(pll a, pll b) { return {a.x+b.x, a.y+b.y}; }

struct SEGTREE {
	const static int M = 524288;
	using T=pll;
	T t[M<<1];
	T la[M<<1];

	void flush(int p) {
		if (la[p] == pll{0, 0}) return;
		rep(i, 2) {
			t[p*2+i] = t[p*2+i] + la[p];
			la[p*2+i] = la[p*2+i] + la[p];
		}
		la[p] = {0, 0};
	}

	void upd(int ul, int ur, ll uv, int p, int ml, int mr) {
		if (ur < ml || mr < ul) return;
		if (ul <= ml && mr <= ur) {
			t[p] = t[p] + pll{1, uv};
			la[p] = la[p] + pll{1, uv};
			return;
		}
		int mid = (ml+mr)/2;
		flush(p);
		upd(ul, ur, uv, p*2, ml, mid);
		upd(ul, ur, uv, p*2+1, mid+1, mr);
		t[p] = t[p*2] + t[p*2+1];
	}

	T ask(int al, int ar, int p, int ml, int mr) {
		if (ar < ml || mr < al) return {0, 0};
		if (al <= ml && mr <= ar) return t[p];
		int mid = (ml+mr)/2;
		flush(p);
		return ask(al, ar, p*2, ml, mid) +
			ask(al, ar, p*2+1, mid+1, mr);
	}
} seg;

void Wow() {
	ll run = 0;

	memset(&fc, 0, sizeof(fc));
	memset(&fv, 0, sizeof(fv));

	rrep(i, n) {
		ll v = a[i];

		{
			auto [cnt, offs] = seg.ask(v, v, 1, 1, V);
			run += v*cnt - offs;
		}

		for (int q=1;;++q) {
			ll ul = v*q, ur = ul+v-1;
			if (V < ul) break;
			ur = min(ur, ll(V));

			ll cnts = fc.s(ur) - fc.s(ul-1);
			ll vals = fv.s(ur) - fv.s(ul-1);
			run += vals - ul * cnts;

			seg.upd(ul, ur, ul, 1, 1, V);
		}

		fc.upd(v, 1);
		fv.upd(v, v);

		ans[i] += run;
	}
}

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> a[i];

	naive();
	Wow();

	rrep(i, n) cout << ans[i] << ' ';

	return 0;
}
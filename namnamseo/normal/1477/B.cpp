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
char s[maxn];
char f[maxn];
pp q[maxn];

struct SEGTREE {
	const static int M = 262144;
	using T=int;
	const static T defval = 0;

	T t[M<<1];
	T lz[M<<1];

	void init(int p, int l, int r) {
		lz[p] = 0;
		if (l == r) {
			t[p] = f[l]-'0';
		} else {
			int mid = (l+r)/2;
			init(p*2, l, mid);
			init(p*2+1, mid+1, r);
			pull(p, l, r);
		}
	}

	void pull(int p, int l, int r) {
		t[p] = t[p*2]+t[p*2+1]; // sum behavior
	}

	void flush(int p, int l, int r) {
		if (l==r || !lz[p]) return;
		lz[p] -= 1;
		int mid = (l+r)/2;
		t[p*2] = lz[p] * (mid-l+1);
		lz[p*2] = 1+lz[p];
		t[p*2+1] = lz[p] * (r-mid);
		lz[p*2+1] = 1+lz[p];
		lz[p] = 0;
	}

	void upd(int ul, int ur, T uv, int p, int ml, int mr) {
		if (ur < ml || mr < ul) return;
		if (ul <= ml && mr <= ur) {
			t[p] = uv * (mr-ml+1); // update behavior
			lz[p] = 1+uv;
			return;
		}
		int mid = (ml+mr)/2;
		flush(p, ml, mr);
		upd(ul, ur, uv, p*2, ml, mid);
		upd(ul, ur, uv, p*2+1, mid+1, mr);
		pull(p, ml, mr);
	}

	T ask(int al, int ar, int p, int ml, int mr) {
		if (ar < ml || mr < al) return defval;
		if (al <= ml && mr <= ar) {
			return t[p];
		}
		int mid = (ml+mr)/2;
		flush(p, ml, mr);
		return // sum behavior
			ask(al, ar, p*2, ml, mid) +
			ask(al, ar, p*2+1, mid+1, mr)
		;
	}

	bool chk(int p, int ml, int mr) {
		if (ml == mr) {
			return (t[p] == (s[ml]-'0'));
		}
		int mid = (ml+mr)/2;
		flush(p, ml, mr);
		return // sum behavior
			chk(p*2, ml, mid) &&
			chk(p*2+1, mid+1, mr);
		;
	}
} seg;

int main()
{
	cppio();
	int tc; cin >> tc;
rep(tci, tc) {
	int z;
	cin >> n >> z;
	cin >> (s+1) >> (f+1);
	rrep(i, z) cin >> q[i].x >> q[i].y;
	seg.init(1, 1, n);
	bool ok = 1;

	for (int i=z; 1<=i; --i) {
		int l, r; tie(l, r) = q[i];
		int len = r-l+1;
		int s = seg.ask(l, r, 1, 1, n);
		if (s*2 == len) {
			ok = 0; break;
		}
		int tgt = (s*2 > len);
		seg.upd(l, r, tgt, 1, 1, n);
	}
	ok = ok && seg.chk(1, 1, n);

	cout << (ok ? "YES" : "NO") << '\n';
}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

using ld = long double;
template<typename T> T K(T a) { return a * a; }
#define K(a) K(1LL * (a))
const ld eps = 1e-12;
#pragma GCC diagnostic ignored "-Wnarrowing"
struct P {
	ld x, y;
    void read(){ int a, b; cin >> a >> b; x = a, y = b; }
    string ts(){ return "("+to_string(x)+", "+to_string(y)+")"; }
    void gen(){ const int mx = 1e4; x = rand()%(2*mx)-mx, y = rand()%(2*mx)-mx; }
	P operator -(const P& he) const {
		return P{x - he.x, y - he.y};
	}
	P operator +(const P& he) const {
		return P{x + he.x, y + he.y};
	}
	ll operator *(const P& he) const {
		return x * he.y - y * he.x;
	}
	P operator *(ld mul) const {
		return P{x * mul, y * mul};
	}
	ld len() { return sqrt(K(x) + K(y)); }
	ld dist(P & b) { return (*this - b).len(); }
	ld angle() { return atan2(y, x); }
	P rotate(ld ang) {
		ld c = cos(ang), s = sin(ang);
		return P{x * c - y * s, x * s + y * c};
	}
};
struct C {
	P o;
	ld r;
	pair<P, P> tangency(P he) {
		ld d = o.dist(he);
		ld alpha = asin(r / d);
		P vec = (o - he) * sqrt(1 - K(r / d)); // *sqrt(d^2-r^2)/d
		// faster: compute 'sin' and 'cos' once
		return {he + vec.rotate(alpha), he + vec.rotate(-alpha)};
	}
};

int n; ll k;
P pts[MAXN];

int bit[2*MAXN];
void upd(int i, int x){ for (; i < 2*n; i |= i+1) bit[i] += x; }
int qry(int i){ int ans=0; for (++i; i > 0; i &= i-1) ans += bit[i-1]; return ans; }
int qry(int l, int r){ return qry(r)-qry(l-1); }

ll cnt(ld r) {
    P orig{0, 0};
    C circ{orig, r};

    ll inside = 0;
    vector<pair<ld, int>> tang; tang.reserve(2*n);
    for (int i = 0; i < n; i++) {
        if (pts[i].dist(orig)-eps <= r) {
            inside++;
            continue;
        }
        auto [p1, p2] = circ.tangency(pts[i]);
        tang.push_back({p1.angle(), i});
        tang.push_back({p2.angle(), i});
    }
    sort(tang.begin(), tang.end());
    int m = sz(tang);

    ll ans = inside*(inside-1)/2 + inside*(n-inside);
    ll cross = 0;

    vector<int> vis(n, -1);
    for (int i = 0; i < m; i++) {
        int c = tang[i].second;
        if (vis[c] == -1) {
            upd(i, 1);
            vis[c] = i;
        } else {
            upd(vis[c], -1);
            cross += qry(vis[c], i);
        }
    }
    ans += (n-inside)*((n-inside)-1)/2 - cross;
    return ans;
}
void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) pts[i].read();

    ld lo = 0, hi = 1e9;
    for (int rep = 0; rep < 50; rep++) {
        ld mid = (lo+hi)/2;
        if (cnt(mid) >= k) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(15) << hi << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void upd(int pos, T val) {
        s[pos + n] = f(s[pos + n], val);
		for (pos += n; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T qry(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int n, a[N];
ll ans = 0;
vector<int> is_less[N], is_big[N];
vector<ar<int, 2>> qs[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];

    int p = 0;
    int inc = -1, dec = n;
    for (int i = 0; i < n; i++) {
        while (p < n && (inc < a[p] && a[p] < dec)) {
            if (p == n-1 || a[p+1] > a[p]) inc = a[p];
            else dec = a[p];
            p++;
        }

        if (p == n) ans += n - i;
        else {
            ans += p - i;
            qs[p].push_back({inc, dec});
        }

        if (inc == a[i]) inc = -1;
        else if (dec == a[i]) dec = n;
    }


    {
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (sz(st) && a[st.back()] > a[i]) st.pop_back();
            if (sz(st)) is_less[st.back()].push_back(i);
            st.push_back(i);
        }

    }
    {
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (sz(st) && a[st.back()] < a[i]) st.pop_back();
            if (sz(st)) is_big[st.back()].push_back(i);
            st.push_back(i);
        }
    }

    Tree bad_less(n, n), bad_big(n, n), bad_pos(n, n);
    /*
    vector<int> bad_less(n, n), bad_big(n, n);
    vector<int> bad_pos(n, n);
    */
    for (int i = n-1; i >= 0; i--) {
        // bad_pos[a[i]] = i;
        bad_pos.upd(a[i], i);
        if (i < n-1) {
            for (int x : is_less[i+1]) {
                bad_less.upd(a[x], x);
                // bad_less[a[x]] = min(bad_less[a[x]], x);
            }
            for (int x : is_big[i+1]) {
                bad_big.upd(a[x], x);
                // bad_big[a[x]] = min(bad_big[a[x]], x);
            }
            /*
            cerr << "> " << a[i+1] << ' ' << is_less[i+1] << '\n';
            cerr << "> " << a[i+1] << ' ' << is_big[i+1] << '\n';
            bad_less[a[i+1]] = min(bad_less[a[i+1]], is_less[i+1]);
            bad_big[a[i+1]] = min(bad_big[a[i+1]], is_big[i+1]);
            */
        }
        for (auto [inc, dec] : qs[i]) {
            // can't have bad_less < a[i], bad_big  > a[i]
            // can't use an element that is in (dec, inc)
            if (a[i] > inc) inc = a[i];
            else if (a[i] < dec) dec = a[i];
            else assert(false);

            assert(dec <= inc);

            int min_r = n;
            min_r = min(min_r, bad_less.qry(0, a[i]-1));
            min_r = min(min_r, bad_big.qry(a[i]+1, n-1));
            min_r = min(min_r, bad_pos.qry(dec+1, inc-1));
            /*
            for (int x = 0; x < a[i]; x++) min_r = min(min_r, bad_less[x]);
            for (int x = a[i]+1; x < n; x++) min_r = min(min_r, bad_big[x]);
            for (int x = dec+1; x < inc; x++) min_r = min(min_r, bad_pos[x]);
            */
            // cerr << i << ' ' << inc << ' ' << dec << ' ' << min_r << endl;

            ans += min_r - i;
        }

        // {prv_less, i}
        // find min i s.t. 
        // {prv_greater, i}
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
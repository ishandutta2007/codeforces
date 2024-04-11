#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const int INF = 1e9+10;

struct Tree {
	typedef pair<int, int> T;
    static constexpr T unit = {MOD, -1};
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0) : s(2*n), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int n, m;
ar<ll, 2> all[2*MAXN];
ll b[MAXN];
vector<int> me[MAXN];
bool good[MAXN];

ll a[MAXN];

priority_queue<int> best;

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> all[i][0], all[i][1] = INF+i, a[i] = all[i][0];
    for (int i = 0; i < m; i++) cin >> all[n+i][0], all[n+i][1] = i;
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(all, all+n+m, [&](auto i, auto j){ return i > j; });

    int mx = -1;
    for (int i = 0; i < n+m; i++) {
        if (all[i][1] < INF) {
            if (mx != -1)
                me[mx].push_back(b[all[i][1]]);
        }
        else mx = max<int>(mx, all[i][1]-INF);
    }
    for (int i = 0; i < n; i++) sort(me[i].begin(), me[i].end());
    ll cur = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        for (auto& c : me[i]) {
            if (cur >= c) { cur -= c, ans++, best.push(c); continue; }
            if (sz(best) && best.top() > c) {
                cur += best.top(); best.pop();
                cur -= c, best.push(c);
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
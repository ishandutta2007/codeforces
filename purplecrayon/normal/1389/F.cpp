#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

typedef vector<int> vi;
const int inf = 5e5+10;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int n;
ar<int, 3> a[N];
map<int, int> mp;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2], --a[i][2];
        mp[a[i][0]]++, mp[a[i][1]]++;
    }

    int cc = 1;
    for (auto& [_, k] : mp) k = cc++;
    for (int i = 0; i < n; i++) {
        a[i][0] = mp[a[i][0]];
        a[i][1] = mp[a[i][1]];
    }
    vector<vector<pair<int, int>>> qr(cc);
    for (int i = 0; i < n; i++) {
        qr[a[i][1]].push_back({a[i][0], a[i][2]});
    }
    Node *segs[2];
    segs[0] = new Node(0, cc + 1);
    segs[1] = new Node(0, cc + 1);
    segs[0]->set(0, cc + 1, 0);
    segs[1]->set(0, cc + 1, 0);
    vector<int> dp(cc);
    for (int r = 1; r < cc; r++) {
        dp[r] = dp[r-1];
        sort(qr[r].rbegin(), qr[r].rend()); // process shorter segments first
        for (auto [l, t] : qr[r]) { // l >= 1
            segs[t]->add(0, l + 1, +1);
            dp[r] = max(dp[r], segs[t]->query(0, r + 1));
        }
        for (int t : {0, 1}) segs[t]->add(r + 1, r + 2, dp[r]);
    }
    cout << dp[cc-1] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
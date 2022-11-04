#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int INF = (int)2e9;

class SegTree {
	vector<int> aint;
	int n;

public:

	SegTree(int _n) : n(_n) {
		int pw = 1;
		while(pw < 2 * n) {
			pw *= 2;
		}
		aint.resize(pw + 1);
	}

	void update(int nod, int left, int right, int pos, int val) {
		if(left == right) {
			aint[nod] = val;
		}
		else {
			int mid = (left + right) / 2;

			if(pos <= mid) update(2 * nod, left, mid, pos, val);
			else update(2 * nod + 1, mid + 1, right, pos, val);

			aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
		}
	}

	int query(int nod, int left, int right, int l, int r) {
		if(l > r) return 0;

		if(l <= left && right <= r) {
			return aint[nod];
		}
		else {
			int mid = (left + right) / 2;
			int ans = -INF;

			if(l <= mid) ans = max(ans, query(2 * nod, left, mid, l, r));
			if(mid < r) ans = max(ans, query(2 * nod + 1, mid + 1, right, l, r));

			return ans;
		}
	}
};




int main() {
#ifdef HOME
    ifstream cin("E.in");
    ofstream cout("E.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector<int> arr(n + 1);
    vector<pair<int, int>> vals;
    for(i = 1; i <= n; i++) {
    	cin >> arr[i];
    	vals.emplace_back(arr[i] - i, i);
    }
    vector<bool> vis(n + 1);
    vector<int> b(k + 1);
    for(i = 1; i <= k; i++) {
    	cin >> b[i];
    	vis[b[i]] = 1;
    }

    sort(vals.begin(), vals.end());

    int mx = 0;
    for(i = 0; i < n; i++) {
    	if(vis[vals[i].second]) {
    		if(mx > vals[i].second) {
    			cout << -1;
    			return 0;
    		}
    		mx = max(mx, vals[i].second);
    	}
    }

    SegTree st(n);

    int ans = 0;
    int pos = 0, cnt = 0;
    for(i = 0; i < n; i++) {
    	int cur = 1 + st.query(1, 1, n, 1, vals[i].second);
		if(cur == 1 && cnt > 0) {
			cur = 0;
		}

    	if(vis[vals[i].second]) {
    		cnt++;
    		while(pos < i) {
    			st.update(1, 1, n, vals[pos].second, 0);
    			pos++;
    		}
    	}

    	if(k == 0) {
    		ans = max(ans, cur);
    	}
    	else if(arr[b[k]] - b[k] <= vals[i].first && vals[i].second >= b[k]) {
    		ans = max(ans, cur);
    	}

    	st.update(1, 1, n, vals[i].second, cur);
    }

    cout << n - ans;

	// 8

    return 0;
}
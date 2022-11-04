#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

struct DSU {
    vector <int> par, sz;
    int n;
    inline void init(int _n) {
        n = _n;
        par.resize(n + 2);
        sz.resize(n + 2, 1);
    }
    int root(int x) {
        if(par[x] == 0)
            return x;
        return par[x] = root(par[x]);
    }
    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            par[x] = y;
            sz[y] += sz[x];
        }
    }
};

const int MAXN = (int)1e5;

int cnt[MAXN + 1];

struct Comp {
	int pos;
	bool operator <(const Comp &other) const {
		if(cnt[pos] == cnt[other.pos]) return pos > other.pos;
		return cnt[pos] > cnt[other.pos];
	}
};


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
    	int n;
    	cin >> n;
    	vector<int> p(n + 1);
    	for(i = 1; i <= n; i++) {
    		int x;
    		cin >> x;
    		p[x] = i;
    		cnt[i] = 1;
    	}

    	DSU dsu; dsu.init(n);

    	multiset<Comp> mst;
    	for(i = 1; i <= n; i++) {
    		mst.insert({i});
    	}

    	bool ans = true;
    	for(i = 1; i <= n; i++) {
    		assert(dsu.root(p[i]) == p[i]);
    		assert(cnt[p[i]] == dsu.sz[p[i]]);

    		if(cnt[p[i]] < cnt[mst.begin() -> pos]) {
				ans = false;
				break;
			}
			mst.erase(mst.find({p[i]}));
			dsu.join(p[i], p[i] + 1);

    		if(dsu.root(p[i]) <= n) {
    			mst.erase(mst.find({dsu.root(p[i])}));

    			cnt[dsu.root(p[i])] += cnt[p[i]];

				mst.insert({dsu.root(p[i])});
    		}
    	}
    	cout << (ans == true ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
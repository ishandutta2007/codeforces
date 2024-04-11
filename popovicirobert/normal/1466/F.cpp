#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int MOD = (int)1e9 + 7;

struct DSU {
    vector <int> par;
    int n;
    void init(int _n) {
        n = _n;
        par.resize(n + 1, -1);
    }
    int root(int x) {
        if(par[x] == -1)
            return x;
        return par[x] = root(par[x]);
    }
    void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            par[x] = y;
        }
    }
};

struct Vector {
	int x, y;
	int pos;
	bool operator<(const Vector& other) const {
		if(x == other.x && y == other.y)
			return pos < other.pos;
		return make_pair(x, y) < make_pair(other.x, other.y);
	}
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n >> m;

	vector<Vector> vectors;
	for(i = 1; i <= n; i++) {
		int k;
		int x, y = 0;
		cin >> k >> x;
		if(k > 1) {
			cin >> y;
		}
		vectors.push_back({x, y, i});
	}

	//sort(vectors.begin(), vectors.end());

	DSU dsu; dsu.init(m);
	vector<int> base;
	for(auto vector : vectors) {
		if(dsu.root(vector.x) != dsu.root(vector.y)) {
			dsu.join(vector.x, vector.y);
			base.push_back(vector.pos);
		}
	}

	int answer = 1, baseCount = (int)base.size();
	for(i = 0; i < baseCount; i++) {
		answer = (2LL * answer) % MOD;
	}

	cout << answer << " " << baseCount << "\n";

	//sort(base.begin(), base.end());
	for(auto pos : base) {
		cout << pos << " ";
	}

    return 0;
}
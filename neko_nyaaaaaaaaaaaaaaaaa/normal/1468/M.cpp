#include <bits/extc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline char gc() {
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++];
}

int readInt() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -readInt();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}

const int MAX = 100000;
const int LIM = 75;

typedef bitset<MAX> bs;

int coordinate_compression(vector<vector<int>> &v) {
	set<int> st;
	map<int, int> cnt;
	for (auto &vec: v) {
		sort(vec.begin(), vec.end());
		for (int i: vec) {
			st.insert(i);
			cnt[i]++;
		}
	}
	vector<int> g;
	for (int i: st) {
		if (cnt[i] > 1) g.push_back(i);
	}

	int ret = 0;
	for (auto &vec: v) {
		vector<int> nxt;
		for (int &i: vec) {
			if (cnt[i] > 1) {
				int gx = lower_bound(g.begin(), g.end(), i) - g.begin();
				nxt.push_back(gx);
				ret = max(ret, gx);
			}
		}
		swap(nxt, vec);
	}
	return ret;
}

__gnu_pbds::gp_hash_table<int, int> h[MAX];

void solve() {
	int n = readInt();
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		int k = readInt(); v[i].resize(k);
		while (k--) {
			v[i][k] = readInt();
		}
	}
	int mxk = coordinate_compression(v);
	for (int i = 0; i <= mxk; i++) {
		h[i].clear();
	}

	vector<pair<vector<int>, int>> small;
	vector<pair<bs, int>> large; 
	vector<pair<vector<int>, int>> llarge;
	for (int i = 0; i < n; i++) {
		auto vec = v[i];
		if (vec.size() >= LIM) {
			bs nxt;
			for (int i: vec) {
				nxt[i] = 1;
			}
			large.emplace_back(nxt, i);
			llarge.emplace_back(vec, i);
		} else {
			small.emplace_back(vec, i);
		}
	}

	// small to small first
	for (auto &[vec, id]: small) {
		int sz = vec.size();
		for (int i = 0; i < sz; i++) {
			for (int j = i+1; j < sz; j++) {
				if (h[vec[i]].find(vec[j]) != h[vec[i]].end()) {
					cout << h[vec[i]][vec[j]]+1 << ' ' << id+1 << '\n';
					return;
				} else {
					h[vec[i]][vec[j]] = id;
				}
			}
		}
	}

	// large to
	int szl = large.size();
	for (int i = 0; i < szl; i++) {
		// large to large
		for (int j = i+1; j < szl; j++) {
			int cnt = 0;
			auto vec = llarge[j].first;
			for (auto &v: vec) {
				if (large[i].first[v]) cnt++;
			}
			if (cnt >= 2) {
				cout << large[i].second+1 << ' ' << large[j].second+1 << '\n';
				return;
			}
		}

		// large to small
		for (auto &[vec, id]: small) {
			int cnt = 0;
			for (auto &v: vec) {
				if (large[i].first[v]) cnt++;
			}
			if (cnt >= 2) {
				cout << large[i].second+1 << ' ' << id+1 << '\n';
				return;
			}
		}
	}

	cout << "-1\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t = readInt();
	while (t--) {
		solve();
	}
	
	return 0;
}
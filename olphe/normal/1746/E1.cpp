#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class UnionFind {
	vector<int>parent;
	vector<int>rank;
	vector<int>score;
	int ret;
public:
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		score.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int node) {
		ret ^= score[node];
		if (parent[node] == node)return node;
		else return Find(parent[node]);
	}
	int Score(int node) {
		ret = 0;
		Find(node);
		return ret;
	}
	void Unite(int u, int v, int c) {
		int ascore = Score(u);
		int bscore = Score(v);
		u = Find(u);
		v = Find(v);
		c ^= bscore ^ ascore;
		if (u == v && (ascore ^ c) != bscore) {
			cout << "!!!!!!!!" << endl;
			return;
		}
		if (u == v)return;
		if (rank[u] < rank[v]) {
			parent[u] = v;
			score[u] ^= c;
		}
		else {
			parent[v] = u;
			score[v] ^= c;
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};


void Question(int bit) {
	vector<int>v;
	for (int i = 1; i <= N; i++) {
		if (i >> bit & 1) {
			v.push_back(i);
		}
	}
	cout << "? ";
	cout << v.size();
	for (auto i : v)cout << " " << i;
	cout << endl;
}

void Answer(vector<int>flag, int to,UnionFind uf) {
	for (int i = 0; i < flag.size(); i++) {
		if (flag[i] == -1) {
			if (uf.Find(i) == i)flag[i] = to;
		}
	}
	for (int i = 0; i < flag.size(); i++) {
		if (flag[i] == -1) {
			flag[i] = flag[uf.Find(i)] ^ uf.Score(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < flag.size(); i++) {
		if (flag[i]) {
			ans |= 1 << i;
		}
	}
	cout << "! " << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int sz = 0;
	for (int i = 0; i < 17; i++) {
		if (N >> i)sz++;
	}
	vector<int>flag(sz, -1);
	UnionFind uf(sz);
	int con = sz;
	while (con>1) {
		vector<int>v;
		for (int i = 0; i < sz; i++) {
			if (i != uf.Find(i))continue;
			if (flag[i] != -1)continue;
			v.push_back(i);
		}
		string a, b, c, d, e;
		Question(v[0]);
		cin >> a;
		Question(v[0]);
		cin >> b;
		if (a == b) {
			flag[v[0]] = a[0] == 'Y';
			con--;
			continue;
		}
		Question(v[1]);
		cin >> c;
		Question(v[1]);
		cin >> d;
		if (c == d) {
			flag[v[1]] = c[0] == 'Y';
			con--;
			continue;
		}
		Question(v[0]);
		cin >> e;
		if (a == e) {
			uf.Unite(v[0], v[1], a != c);
		}
		else {
			flag[v[0]] = e[0] == 'Y';
		}
		con--;
	}
	Answer(flag, 1, uf);
	string s;
	cin >> s;
	if (s == ":)") {
		return 0;
	}
	Answer(flag, 0, uf);
	cin >> s;
}
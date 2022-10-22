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
#include "functional"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

struct Node {
	int x, y, z,index;
	Node(const int xx = 0, const int yy = 0, const int zz = 0) {
		x = xx, y = yy, z = zz;
		return;
	}
	bool operator<(const Node&n)const {
		return make_pair(x, make_pair(y, z)) < make_pair(n.x, make_pair(n.y, n.z));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<Node>v(N);
	int cnt = 0;
	for (auto &i : v) {
		cin >> i.x >> i.y >> i.z;
		i.index = ++cnt;
	}
	sort(v.begin(), v.end());
	vector<Node>w;
	for (int i = 1; i < N; i++) {
		if (v[i].x == v[i - 1].x&&v[i].y == v[i - 1].y) {
			cout << v[i].index << " " << v[i - 1].index << endl;
			i++;
			if (i == N - 1) {
				w.push_back(v.back());
			}
		}
		else if (i == N - 1) {
			w.push_back(v[i]);
			w.push_back(v[i - 1]);
		}
		else w.push_back(v[i - 1]);
	}
	sort(w.begin(), w.end());
	v = w;
	w.clear();
	for (int i = 1; i < v.size(); i++) {
		if (v[i].x == v[i - 1].x) {
			cout << v[i].index << " " << v[i - 1].index << endl;
			i++;
			if (i == v.size() - 1) {
				w.push_back(v.back());
			}
		}
		else if (i == v.size() - 1) {
			w.push_back(v[i]);
			w.push_back(v[i - 1]);
		}
		else w.push_back(v[i - 1]);
	}
	sort(w.begin(), w.end());
	for (int i = 1; i < w.size(); i += 2) {
		cout << w[i].index << " " << w[i - 1].index << endl;
	}
}
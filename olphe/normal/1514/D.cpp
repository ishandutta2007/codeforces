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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

constexpr int block = 500;

struct Query {
	int l, r, idx;
	Query(int idx) :idx(idx) {
		cin >> l >> r;
		l--;
	}
	bool operator<(const Query& q)const {
		return make_pair(l / 500, r) < make_pair(q.l / 500, q.r);
	}
};

void Solve() {
	cin >> N >> M;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	vector<Query>q;
	for (int i = 0; i < M; i++) {
		q.push_back(Query(i));
	}
	sort(q.begin(), q.end());
	vector<int>num(N + 1);
	vector<int>fre(N + 1);
	fre[0] = N;
	int mx = 0;
	int l = 0, r = 0;
	vector<int>ans(M);
	for (auto i : q) {
		while (i.l < l) {
			l--;
			fre[num[v[l]]]--;
			if (num[v[l]] == mx) {
				mx++;
			}
			num[v[l]]++;
			fre[num[v[l]]]++;
		}
		while (r < i.r) {
			fre[num[v[r]]]--;
			if (num[v[r]] == mx) {
				mx++;
			}
			num[v[r]]++;
			fre[num[v[r]]]++;
			r++;
		}
		while (l < i.l) {
			fre[num[v[l]]]--;
			if (fre[num[v[l]]] == 0 && num[v[l]] == mx) {
				mx--;
			}
			num[v[l]]--;
			fre[num[v[l]]]++;
			l++;
		}
		while (i.r < r) {
			r--;
			fre[num[v[r]]]--;
			if (fre[num[v[r]]] == 0 && num[v[r]] == mx) {
				mx--;
			}
			num[v[r]]--;
			fre[num[v[r]]]++;
		}
		ans[i.idx] = max(1, mx * 2 - (r - l));
	}
	for (auto i : ans)cout << i << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}
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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

struct Query {
	int l, r, index;
	bool operator <(const Query& q)const {
		if (l / 500 < q.l / 500)return true;
		else if (l / 500 > q.l / 500)return false;
		if (r < q.r)return true;
		return false;
	}
	bool operator >(const Query& q)const {
		if (l / 500 > q.l / 500)return true;
		else if (l / 500 < q.l / 500)return false;
		if (r > q.r)return true;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<Query>query(K);
	for (int i = 0; i < K; i++) {
		cin >> query[i].l >> query[i].r;
		query[i].l--;
		query[i].r--;
		query[i].index = i;
	}
	vector<long long int>ans(K);
	sort(query.begin(), query.end());
	vector<long long int>num(1000001);
	long long int fig = 0;
	R = -1;
	for (auto i : query) {
		//cout << i.l << " " << i.r << endl;
		if (R > i.r) {
			for (auto &j : num)j = 0;
			fig = 0;
			L = 0;
			R = -1;
		}
		for (int j = R + 1; j <= i.r; j++) {
			num[v[j]]++;
			fig += (num[v[j]] * 2 - 1)*v[j];
		}
		if (L > i.l) {
			for (int j = i.l; j < L; j++) {
				num[v[j]]++;
				fig += (num[v[j]] * 2 - 1)*v[j];
			}
		}
		else if (L < i.l) {
			for (int j = L; j < i.l; j++) {
				num[v[j]]--;
				fig -= (num[v[j]] * 2 + 1)*v[j];
			}
		}
		L = i.l;
		R = i.r;
		ans[i.index] = fig;
	//	cout << fig << endl;
	}
	for (auto i : ans)cout << i << "\n";
	return 0;
}
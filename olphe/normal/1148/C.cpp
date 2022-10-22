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

using namespace std;

//const long long int MOD = 1000000007;
const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	vector<int>p(N);
	for (auto &i : v) {
		cin >> i;
		i--;
	}
	for (int i = 0; i < N; i++) {
		p[v[i]] = i;
	}
	vector<pair<int, int>>ans;
	for (int i = N / 2; i < N; i++) {
		if (abs(p[i] - i) * 2 >= N) {
			ans.push_back({ i,p[i] });
			int num = v[i];
			swap(v[i], v[p[i]]);
			swap(p[num], p[i]);
		}
		if (p[i] < i) {
			ans.push_back({ N - 1,p[i] });
			int num = v[N - 1];
			swap(v[N - 1], v[p[i]]);
			swap(p[num], p[i]);
		}
		if (p[i] > i) {
			ans.push_back({ 0,p[i] });
			int num = v[0];
			swap(v[0], v[p[i]]);
			swap(p[num], p[i]);
		}
		if (abs(p[i] - i) * 2 >= N) {
			ans.push_back({ i,p[i] });
			int num = v[i];
			swap(v[i], v[p[i]]);
			swap(p[num], p[i]);
		}
		i = N - 1 - i;
		if (abs(p[i] - i) * 2 >= N) {
			ans.push_back({ i,p[i] });
			int num = v[i];
			swap(v[i], v[p[i]]);
			swap(p[num], p[i]);
		}

		if (p[i] > i) {
			ans.push_back({ 0,p[i] });
			int num = v[0];
			swap(v[0], v[p[i]]);
			swap(p[num], p[i]);
		}
		if (p[i] < i) {
			ans.push_back({ N-1,p[i] });
			int num = v[N-1];
			swap(v[N-1], v[p[i]]);
			swap(p[num], p[i]);
		}
		if (abs(p[i] - i) * 2 >= N) {
			ans.push_back({ i,p[i] });
			int num = v[i];
			swap(v[i], v[p[i]]);
			swap(p[num], p[i]);
		}
		i = N - 1 - i;
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i.first+1 << " " << i.second+1 << endl;
}
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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>v(N);
	for (auto&i : v)cin >> i;
	vector<long long int>w(N);
	for (auto&i : w)cin >> i;
	multiset<pair<long long int,int>>m;
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] % 100 == 0)continue;
		M -= v[i] % 100;
		m.insert({ w[i] * (100 - v[i] % 100) , i });
		while (M < 0) {
			auto box = *m.begin();
			m.erase(m.begin());
			M += 100;
			ans += box.first;
			v[box.second] -= v[box.second] % 100;
			v[box.second] += 100;
		}
	}
	cout << ans << endl;
	for (auto i : v)cout << i / 100 << " " << i % 100 << endl;
	return 0;
}
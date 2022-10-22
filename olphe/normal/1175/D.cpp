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

const long long int MOD = 1000000007;
//const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>box;
	reverse(v.begin(), v.end());
	long long int add = 0;
	for (int i = 0; i < N-1; i++) {
		add += v[i];
		box.push_back(add);
	}
	add += v.back();
	sort(box.begin(), box.end());
	reverse(box.begin(), box.end());
	long long int ans = add;
	for (int i = 1; i < M; i++) {
		ans += box[i - 1];
	}
	cout << ans << endl;
}
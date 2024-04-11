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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	K++;
	vector<long long int>num(N);
	for (auto &i : num)cin >> i;
	long long int ans = 0;
	sort(num.rbegin(), num.rend());
	priority_queue<pair<long long int, int>>PQ;
	for (int i = 0; i < K; i++)PQ.push({ 0,i });
	for (int i = 0; i < N; i++) {
		auto box = PQ.top();
		PQ.pop();
		ans += box.first;
		box.first += num[i];
		PQ.push(box);
	}
	cout << ans << endl;
}
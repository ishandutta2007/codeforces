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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>v(N);
	priority_queue<int>big;
	vector<int>small;
	for (auto &i : v) {
		cin >> i;
		if (i > K)big.push(i);
		else small.push_back(i);
	}
	sort(small.rbegin(), small.rend());
	long long int ssum = accumulate(small.begin(), small.end(), 0LL);
	long long int bsum = 0;
	long long int ans = ssum;
	int length = N;
	int used = 0;
	while (!big.empty()) {
		auto box = big.top();
		big.pop();
		used++;
		length = N - (used - 1)*(M + 1) - 1;
		bsum += box;
		if (length < 0)break;
		while (length < small.size()) {
			ssum -= small.back();
			small.pop_back();
		}
		ans = max(ans, ssum + bsum);
		if (length == 0)break;
	}
	cout << ans << endl;
}
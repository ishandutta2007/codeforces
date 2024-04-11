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

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >>M>> K;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>w;
	for (int i = 1; i < N; i++)w.push_back(v[i] - v[i - 1]);
	sort(w.begin(), w.end(), greater<long long int>());
	long long int ans = accumulate(w.begin(), w.end(), 0LL) + K;
	for (int i = 0; i < K-1; i++)ans -= w[i];
	cout << ans << endl;
}
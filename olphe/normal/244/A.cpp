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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(K);
	for (auto &i : v)cin >> i;
	vector<int>w(N * K + 1,1);
	for (auto i : v)w[i] = 0;
	vector<int>u;
	for (int i = 1; i <= N * K; i++) {
		if (w[i])u.push_back(i);
	}
	for (int i = 0; i < K; i++) {
		cout << v[i];
		for (int j = 1; j < N; j++) {
			cout << " " << u.back();
			u.pop_back();
		}
		cout << endl;
	}
}
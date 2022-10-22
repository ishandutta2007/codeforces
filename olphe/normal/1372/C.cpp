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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		int a = 0;
		int b = 0;
		vector<int>w;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			if (i + 1 != v[i]) {
				b = 1;
				w.push_back(i);
			}
			if (i+1 == v[i])a = 1;
		}
		if (!b)cout << 0 << endl;
		else if (!a)cout << 1 << endl;
		else if (w.size() && w.front() == w.back() - w.size() + 1)cout << 1 << endl;
		else cout << 2 << endl;
	}
}
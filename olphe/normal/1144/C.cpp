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

	cin >> N;
	vector<int>v(200001);
	for (int i = 0; i < N; i++) {
		cin >> K;
		v[K]++;
		if (v[K] > 2) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	vector<int>a;
	vector<int>b;
	for (int i = 0; i <= 200000; i++) {
		if (v[i] == 2) {
			a.push_back(i);
			b.push_back(i);
		}
		else if (v[i] == 1) {
			a.push_back(i);
		}
	}
	reverse(b.begin(), b.end());
	cout << a.size() << endl;
	for (auto i : a)cout << i << " ";
	cout << endl;
	cout << b.size() << endl;
	for (auto i : b)cout << i << " ";
	cout << endl;
}
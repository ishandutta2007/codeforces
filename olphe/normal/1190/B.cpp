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
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string win = "sjfnb";
	string lose = "cslnb";
	//string win = "win";
	//string lose = "lose";
	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	if (N == 1) {
		if (v[0] & 1)cout << win << endl;
		else cout << lose << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		K += v[i] == v[i - 1];
		if (v[i] == v[i - 1]&& i > 1) {
			K += v[i] == v[i - 2] + 1;
		}
	}
	if (K >= 2) {
		cout << lose << endl;
		return 0;
	}
	if (v[0] == v[1] && !v[0]) {
		cout << lose << endl;
		return 0;
	}
	long long int sum = 0;
	for (auto i : v)sum += i;
	long long int fin = N * (N - 1) / 2;
	if ((sum & 1) == (fin & 1)||sum<fin)cout << lose << endl;
	else cout << win << endl;
}
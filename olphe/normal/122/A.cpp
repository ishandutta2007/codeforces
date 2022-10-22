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

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v;
	v.push_back(4);
	v.push_back(7);
	v.push_back(44);
	v.push_back(47);
	v.push_back(74);
	v.push_back(77);
	v.push_back(444);
	v.push_back(447);
	v.push_back(474);
	v.push_back(477);
	v.push_back(744);
	v.push_back(747);
	v.push_back(774);
	v.push_back(777);
	for (auto i : v) {
		while (N%i == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
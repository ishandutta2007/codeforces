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

//const long long int MOD = 1000000007;
const long long  int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>w;
	for (int i = 0; i < N - 1; i++) {
		if (v[i] >= v[i + 1])w.push_back(v[i]);
	}
	w.push_back(v.back());
	cout << w.size() << endl;
	for (auto i : w)cout << i << " ";
	cout << endl;
	return 0;
}
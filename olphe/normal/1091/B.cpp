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

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>>v(N);
	vector<pair<int, int>>w(N);
	for (auto &i : v)cin >> i.first >> i.second;
	for (auto &i : w)cin >> i.first >> i.second;
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	cout << v.front().first + w.back().first << " " << v.front().second + w.back().second << endl;
	return 0;
}
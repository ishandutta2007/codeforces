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
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	map<char, int>m;
	m['r'] = 1;
	m['p'] = 1;
	m['g'] = 1;
	m['b'] = 1;
	m['o'] = 1;
	m['y'] = 1;
	for (auto i : s) {
		m[i[0]] = 0;
	}
	map<char, string>mm;
	mm['r'] = "Reality";
	mm['p'] = "Power";
	mm['g'] = "Time";
	mm['b'] = "Space";
	mm['o'] = "Soul";
	mm['y'] = "Mind";
	vector<string>ans;
	for (auto i : m) {
		if (i.second)ans.push_back(mm[i.first]);
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << endl;
	return 0;
}
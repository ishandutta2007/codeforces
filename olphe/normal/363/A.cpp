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
	vector<string>ans;
	do {
		string s;
		if (N % 10 >= 5)s += "-O|";
		else s += "O-|";
		for (int i = 0; i < N % 5; i++)s.push_back('O');
		s.push_back('-');
		while (s.size() < 8)s.push_back('O');
		N /= 10;
		ans.push_back(s);
	} while (N);
	for (auto i : ans)cout << i << endl;
}
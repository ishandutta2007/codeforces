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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	string s;
	cin >> s;
	K -= 1 << (s.back() - 'a');
	s.pop_back();
	K += 1 << (s.back() - 'a');
	s.pop_back();
	vector<int>num(26);
	for (auto i : s) {
		num[i - 'a']++;
	}
	vector<int>amari(27);
	K = abs(K);
	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < num[i]; j++) {
			K = abs(K - (1 << i));
		}
	}
	if(K==0)cout << "Yes\n";
	else cout << "No\n";
}
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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;

	while (K--) {
		string s, t;
		cin >> s >> t;
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		int st = 0;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == '1') {
				st = i;
				break;
			}
		}
		for(int j=st;j<s.size();j++){
			if (s[j] == '1') {
				cout << j - st << endl;
				break;
			}
		}
	}
}
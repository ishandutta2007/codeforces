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
	string s;
	cin >> s;
	string t;
	for (int i = 0; i < N; i++) {
		if (i + 1 < N&&s[i] == 'g'&&s[i + 1] == 'o'&&t.size() && t.back() == '*') {
			i++;
			continue;
		}
		if (i + 2 < N) {
			if (s[i] == 'o'&&s[i + 1] == 'g'&&s[i + 2] == 'o') {
			
					t += "***";
				i+=2;
			}
			else {
				t.push_back(s[i]);
			}
		}
		else {
			t.push_back(s[i]);
		}
	}
	cout << t << endl;
}
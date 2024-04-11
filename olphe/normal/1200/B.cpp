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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;
//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> L;
	while (L--) {
		cin >> N >> M >> K;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		bool flag = true;
		for (int i = 0; i < N - 1; i++) {
			M += v[i];
			v[i] = 0;
			if (M >= v[i + 1] - K) {
			    
				M -= max(0LL,v[i + 1] - K);
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
}
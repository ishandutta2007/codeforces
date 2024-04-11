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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> K;
	string ans;
	for (int i = 0; i < H-1; i++)ans.push_back('U');
	for (int i = 0; i < W-1; i++)ans.push_back('L');
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W-1; j++) {
			if (i & 1)ans.push_back('L');
			else ans.push_back('R');
		}
		ans.push_back('D');
	}
	cout << ans.size() << endl;
	cout << ans << endl;
}
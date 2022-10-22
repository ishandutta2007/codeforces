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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> K;
	vector<int>two(vector<int>(2));
	vector<vector<int>>h(H, vector<int>(2));
	vector<vector<int>>w(W, vector<int>(2));
	int hfree = H;
	int hng = 0;
	int wfree = W;
	int wng = 0;
	int naname = 0;
	long long ans = 0;
	ans = power(2, H, MOD);
	ans += power(2, W, MOD);
	ans -= 2;
	map<pair<int, int>, int>mp;
	while (K--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		if (mp.find({ a,b }) != mp.end()) {
			int bef = mp[{a, b}];
			{
				two[bef ^ ((a ^ b) & 1)]--;
			}
			{
				h[a][bef ^ (b & 1)]--;
				if (h[a][bef ^ (b & 1)] == 0 && h[a][bef ^ 1 ^ (b & 1)]) {
					hng--;
				}
				if (h[a][bef ^ (b & 1)] == 0 && h[a][bef ^ 1 ^ (b & 1)] == 0) {
					hfree++;
				}
			}
			{
				w[b][bef ^ (a & 1)]--;
				if (w[b][bef ^ (a & 1)] == 0 && w[b][bef ^ 1 ^ (a & 1)]) {
					wng--;
				}
				if (w[b][bef ^ (a & 1)] == 0 && w[b][bef ^ 1 ^ (a & 1)] == 0) {
					wfree++;
				}
			}
			mp.erase({ a,b });
		}
		if (c != -1) {
			mp[{a, b}] = c;
			two[c ^ ((a ^ b) & 1)]++;
			{
				h[a][c ^ (b & 1)]++;
				if (h[a][c ^ (b & 1)] == 1 && h[a][c ^ 1 ^ (b & 1)])hng++;
				if (h[a][c ^ (b & 1)] == 1 && h[a][c ^ 1 ^ (b & 1)] == 0)hfree--;
			}
			{
				w[b][c ^ (a & 1)]++;
				if (w[b][c ^ (a & 1)] == 1 && w[b][c ^ 1 ^ (a & 1)])wng++;
				if (w[b][c ^ (a & 1)] == 1 && w[b][c ^ 1 ^ (a & 1)] == 0)wfree--;
			}
		}
		ans = 0;
		if (!hng) {
			ans += power(2, hfree, MOD);
		}
		if (!wng) {
			ans += power(2, wfree, MOD);
		}
		ans -= !two[0];
		ans -= !two[1];
		ans %= MOD;
		//cout << hfree << " " << hng << " " << wfree << " " << wng << " " << two[0] << " " << two[1] << endl;
		if (hng && wng) {
			cout << 0 << endl;
		}
		else if (hng) {
			cout << power(2, wfree, MOD) << endl;
		}
		else if (wng) {
			cout << power(2, hfree, MOD) << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}
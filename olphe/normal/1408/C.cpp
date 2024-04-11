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

	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<long double>v(N);
		for (auto &i : v)cin >> i;
		long double ap = 0, bp = K;
		int anx = 0;
		int bnx = N - 1;
		long double ret = 0;
		long double av = 1, bv = -1;
		while (anx <= bnx) {
			if ((v[anx] - ap) / av < (v[bnx] - bp) / bv) {
				ret += (v[anx] - ap) / av;
				bp += (v[anx] - ap) / av * bv;
				ap = v[anx];
				av++;
				anx++;
			}
			else {
				ret += (v[bnx] - bp) / bv;
				ap += (v[bnx] - bp) / bv * av;
				bp = v[bnx];
				bv--;
				bnx--;
			}
		}
		ret += (bp - ap) / (av - bv);
		cout << setprecision(20) << ret << endl;
	}
}
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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	string s, t, u;
	cin >> s >> t >> u;
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i = 0; i < N * 2; i++) {
		a += s[i] == '0';
		b += t[i] == '0';
		c += u[i] == '0';
	}
	int rev = 0;
	string x, y;
	if (a >= N && b >= N) {
		x = s, y = t;
	}
	else if (a >= N && c >= N) {
		x = s, y = u;
	}
	else if (b >= N && c >= N) {
		x = t, y = u;
	}
	else {
		a = 2 * N - a;
		b = 2 * N - b;
		c = 2 * N - c;
		rev = 1;
		for (auto& i : s)i ^= '1' ^ '0';
		for (auto& i : t)i ^= '1' ^ '0';
		for (auto& i : u)i ^= '1' ^ '0';
		if (a >= N && b >= N) {
			x = s, y = t;
		}
		else if (a >= N && c >= N) {
			x = s, y = u;
		}
		else {
			x = t, y = u;
		}
	}
	string ans;
	int aidx = 0;
	int bidx = 0;
	while (aidx < N * 2 || bidx < N * 2) {
		int anum = 0, bnum = 0;
		int add = 0;
		while (aidx < N * 2) {
			if (x[aidx] == '1') {
				aidx++;
				anum++;
			}
			else {
				add = 1;
				break;
			}
		}
		while (bidx < N * 2) {
			if (y[bidx] == '1') {
				bidx++;
				bnum++;
			}
			else {
				add = 1;
				break;
			}
		}
		aidx++;
		bidx++;
	//	cout << anum << " " << bnum << endl;
		ans += string(max(anum, bnum), '1');
		if(add)ans.push_back('0');
	}
	if (rev) {
		for (auto& i : ans)i ^= '1' ^ '0';
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}

}
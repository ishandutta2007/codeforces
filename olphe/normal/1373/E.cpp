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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>sum(1000001);
	for (int i = 1; i <= 1000000; i++) {
		int box = i;
		while (box) {
			sum[i] += box % 10;
			box /= 10;
		}
	}
	cin >> K;
	while (K--) {
		cin >> N >> M;
		if (M == 0) {
			string s;
			while (N) {
				s += min(9LL, N) + '0';
				N -= min(9LL, N);
			}
			reverse(s.begin(), s.end());
			cout << s << endl;
		}
		else if (M == 1) {
			string s;
			if (N & 1) {
				N >>= 1;
				N++;
				while (N) {
					s += min(9LL, N) + '0';
					N -= min(9LL, N);
				}
				reverse(s.begin(), s.end());
				s.back()--;
				cout << s << endl;
			}
			else {
				N -= 9;
				if (N < 0) {
					cout << "-1" << endl;
				}
				else {
					N >>= 1;
					N++;
					while (N) {
						s += min(9LL, N) + '0';
						N -= min(9LL, N);
					}
					reverse(s.begin(), s.end());
					s.back()--;
					if (s == "0")cout << 9 << endl;
					else cout << s + "9" << endl;
				}
			}
		}
		else{
			for (int i = 0; i <= 999990; i++) {
				int box = 0;
				for (int j = 0; j <= M; j++) {
					box += sum[i + j];
				}
				if (box == N) {
					cout << i << endl;
					break;
				}
				if (i == 999990)cout << -1 << endl;
			}
			
		}
	}
}
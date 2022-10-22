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
	int a = 0, c = 0, g = 0, t = 0, q = 0;
	for (auto i : s) {
		if (i == 'A')a++;
		else if (i == 'G')g++;
		else if (i == 'C')c++;
		else if (i == 'T')t++;
	}
	if (N % 4) {
		cout << "===" << endl;
		return 0;
	}
	if (a > N / 4) {
		cout << "===" << endl;
		return 0;
	}
	if (g > N / 4) {
		cout << "===" << endl;
		return 0;
	}
	if (c > N / 4) {
		cout << "===" << endl;
		return 0;
	}
	if (t > N / 4) {
		cout << "===" << endl;
		return 0;
	}
	for (auto &i : s) {
		if (i == '?') {
			if (a < N / 4) {
				a++;
				i = 'A';
			}
			else if (g < N / 4) {
				g++;
				i = 'G';
			}
			else if (c < N / 4) {
				c++;
				i = 'C';
			}
			else if (t < N / 4) {
				t++;
				i = 'T';
			}
		}
	}
	cout << s << endl;
}
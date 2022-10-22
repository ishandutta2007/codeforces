#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> H >> W;
	string s[200];
	for (int i = 0; i < H; i++)cin >> s[i];
	bool flag = true;
	if (H % 3 == 0) {
		char c = s[0][0];
		for (int i = 0; i < H / 3; i++) {
			for (auto j : s[i]) {
				if (j != c) {
					flag = false;
					break;
				}
			}
		}
		if (s[0][0] == s[H / 3][0]) {
			flag = false;
		}
		else {
			c = s[H / 3][0];
			for (int i = H / 3; i < H * 2 / 3; i++) {
				for (auto j : s[i]) {
					if (j != c) {
						flag = false;
						break;
					}
				}
			}
		}
		if (s[0][0] == s[H * 2 / 3][0] || s[H / 3][0] == s[H * 2 / 3][0]) {
			flag = false;
		}
		else {
			c = s[H * 2 / 3][0];
			for (int i = H * 2 / 3; i < H; i++) {
				for (auto j : s[i]) {
					if (j != c) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag) {
			cout << "YES\n";
			return 0;
		}
	}
	flag = true;
	if (W % 3 == 0) {
		char c = s[0][0];
		for (int i = 0; i < W / 3; i++) {
			for(int j=0;j<H;j++){
				if (s[j][i] != c) {
					flag = false;
					break;
				}
			}
		}
		if (s[0][0] == s[0][W/3]) {
			flag = false;
		}
		else {
			c = s[0][W/3];
			for (int i = W/3; i < W*2 / 3; i++) {
				for (int j = 0; j<H; j++) {
					if (s[j][i] != c) {
						flag = false;
						break;
					}
				}
			}
		}
		if (s[0][0] == s[0][W*2/3] || s[0][W/3] == s[0][W*2/3]) {
			flag = false;
		}
		else {
			c = s[0][W*2/3];
			for (int i = W *2/ 3; i <  W; i++) {
				for (int j = 0; j<H; j++) {
					if (s[j][i] != c) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
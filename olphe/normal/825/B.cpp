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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s[18];
	for (int i = 4; i <= 13; i++) {
		cin >> s[i];
		s[i] = "...." + s[i] + "....";
	}
	for (int i = 0; i < 18; i++) {
		s[0] += '.';
		s[1] += '.';
		s[2] += '.';
		s[3] += '.';
		s[14] += '.';
		s[15] += '.';
		s[16] += '.';
		s[17] += '.';
	}
	for (int i = 4; i < 14; i++) {
		for (int j = 4; j < 14; j++) {
			if (s[i][j] != '.')continue;
			int box = 0;
			for (int k = 1;; k++) {
				if (s[i][j + k] == 'X')box++;
				else break;
			}
			for (int k = 1;; k++) {
				if (s[i][j - k] == 'X')box++;
				else break;
			}
			if (box > 3) {
				cout << "YES\n";
				return 0;
			}
			box = 0;
			for (int k = 1;; k++) {
				if (s[i + k][j] == 'X')box++;
				else break;
			}
			for (int k = 1;; k++) {
				if (s[i - k][j] == 'X')box++;
				else break;
			}
			if (box > 3) {
				cout << "YES\n";
				return 0;
			}
			box = 0;
			for (int k = 1;; k++) {
				if (s[i + k][j + k] == 'X')box++;
				else break;
			}
			for (int k = 1;; k++) {
				if (s[i - k][j - k] == 'X')box++;
				else break;
			}
			if (box > 3) {
				cout << "YES\n";
				return 0;
			}
			box = 0;
			for (int k = 1;; k++) {
				if (s[i + k][j - k] == 'X')box++;
				else break;
			}
			for (int k = 1;; k++) {
				if (s[i - k][j + k] == 'X')box++;
				else break;
			}
			if (box > 3) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}
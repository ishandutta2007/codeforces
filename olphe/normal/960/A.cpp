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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	char flag = 'a';
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (flag == 'a') {
			if (s[i] == flag) {
				a++;
			}
			else if (s[i] == 'b') {
				b = 1;
				flag++;
			}
			else {
				a = 0;
				flag++;
			}
		}
		else if (flag == 'b') {
			if (s[i] == flag) {
				b++;
			}
			else if (s[i] == 'c') {
				c = 1;
				flag++;
			}
			else {
				b = 0;
				flag++;
			}
		}
		else if (flag == 'c') {
			if (s[i] == flag) {
				c++;
			}
			else {
				c = 0;
				flag++;
				break;
			}
		}
	}
	if (flag == 'd' || !a || !b || !c) {
		cout << "NO" << endl;
		return 0;
	}
	if (a == c || b == c) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
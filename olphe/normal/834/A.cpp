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
	string s, t;
	cin >> s >> t;
	cin >> N;
	string box = { 'v','<','^','>' };
	if (N % 2 == 0) {
		cout << "undefined\n";
		return 0;
	}
	int b, a;
	for (int i = 0; i < 4; i++) {
		if (s[0] == box[i])b = i;
		if (t[0] == box[i])a = i;
	}
	if (box[(b + N) % 4] == box[a]) {
		cout << "cw\n";
	}
	else cout << "ccw\n";
	return 0;
}
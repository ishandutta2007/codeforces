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
	cin >> N;
	while (N>0) {
		string s;
		cin >> s;
		N -= s.size();
		N--;
		long long int box = 0;
		for (auto j : s) {
			if (j >= 'A'&&j <= 'Z')box++;
		}
		ans = max(ans, box);
	}
	cout << ans << endl;
	return 0;
}
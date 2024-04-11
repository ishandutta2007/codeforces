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
	cin >> N >> M;
	string s;
	cin >> s;
	int l[26] = {};
	int r[26] = {};
	for (int i = 0; i < 26; i++) {
		l[i] = INT_MAX;
		r[i] = INT_MIN;
	}
	for (int i = 0; i < s.size(); i++) {
		l[s[i] - 'A'] = min(l[s[i]-'A'] , i);
		r[s[i] - 'A'] = max(r[s[i]-'A'] , i);
	}
	for (int i = 0; i < s.size(); i++) {
		int num = 0;
		for (int j = 0; j < 26; j++) {
			if (l[j] <= i&&r[j] >= i)num++;
		}
		if (num > M) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
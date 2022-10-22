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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == '0')M++;
		else break;
	}
	string t;
	for (int i = 0; i < N - M; i++) {
		t += s[i];
	}
	string u = t;
	reverse(u.begin(), u.end());
	if (t == u) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
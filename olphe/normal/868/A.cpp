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
	cin >> N;
	bool a = false, b = false;
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		if (s == t) {
			cout << "YES\n";
			return 0;
		}
		if (t[1] == s[0]) {
			a = true;
		}
		if (t[0] == s[1]) {
			b = true;
		}
	}
	if (a&&b) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
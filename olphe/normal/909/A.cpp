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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	s.push_back('z');
	string u;
	u.push_back(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] < t[0]) {
			u.push_back(s[i]);
		}
		else {
			u.push_back(t[0]);
			break;
		}
	}
	cout << u << endl;
	return 0;
}
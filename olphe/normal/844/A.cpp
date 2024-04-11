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

long long int N, M, K, W, H, L, R;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	cin >> N;
	if (s.size() < N) {
		cout << "impossible\n";
		return 0;
	}
	map<char, int>m;
	for (auto i : s)m[i]++;
	for (char i = 'a'; i <= 'z'; i++) {
		if (m[i])M++;
	}
	cout << max((long long int)0, N - M) << endl;
	return 0;
}
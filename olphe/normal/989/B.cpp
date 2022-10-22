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

	cin >> N >> M;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (i + M >= N)break;
		if (s[i] == '.'&&s[i + M] == '.') {
			s[i] = '0';
			s[i + M] = '1';
		}
		else if (s[i] == '.') {
			s[i] = '0';
			if (s[i + M] == '0') {
				s[i] = '1';
			}
		}
		else if (s[i + M] == '.') {
			s[i + M] = '0';
			if (s[i] == '0') {
				s[i + M] = '1';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (s[i] == '.')s[i] = '0';
	}
	for (int i = 0; i < N; i++) {
		if (i + M >= N)break;
		if (s[i] != s[i + M]) {
			cout << s << endl;
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
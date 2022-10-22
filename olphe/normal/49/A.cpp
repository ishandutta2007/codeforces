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
#include "numeric"
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	N = s.size();
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] != ' '&&s[i] != '?') {
			N = i + 2;
			break;
		}
	}
	if (s[N - 2] == 'a' || s[N - 2] == 'i' || s[N - 2] == 'u' || s[N - 2] == 'e' || s[N - 2] == 'o' || s[N - 2] == 'y') cout << "YES\n";
	else if (s[N - 2] == 'A' || s[N - 2] == 'I' || s[N - 2] == 'U' || s[N - 2] == 'E' || s[N - 2] == 'O' || s[N - 2] == 'Y') cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
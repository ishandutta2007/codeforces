#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
const long long int MOD = 1000000007;

int N,M;
char letter[2][200000];

int main() {
	cin >> letter[0];
	cin >> letter[1];
	for (int i = 0; letter[0][i] != NULL; i++) {
		N = i;
	}
	for (int i = 0; letter[1][i] != NULL; i++) {
		M = i;
	}
	if (N != M) {
		cout << max(N, M) + 1 << endl;
		return 0;
	}
	for (int i = 0; i <= N; i++) {
		if (letter[0][i] != letter[1][i]) {
			cout << N + 1 << endl;
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
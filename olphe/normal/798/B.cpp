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

int N;
string S[50][50];
int far;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> S[i][0];
	far = S[0][0].size();
	for (int loop = 0; loop < N; loop++) {
		for (int i = 1; i < far; i++) {
			for (int j = 0; j < far; j++) {
				S[loop][i] += S[loop][0][(i + j) % far];
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < far; i++) {
		int box = i;
		for (int j = 1; j < N; j++) {
			bool flag = false;
			for (int k = 0; k < far; k++) {
				if (S[0][i] == S[j][k]) {
					box += k;
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "-1\n";
				return 0;
			}
		}
		ans = min(ans, box);
	}
	cout << ans << endl;
	return 0;
}
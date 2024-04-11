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
const long long int MOD =1000000007;

int N, M ;
int num[2][100];
int K;
bool flag;

int main() {
	cin >> N>>M;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		K = (num[1][i] + M - num[0][0]) % M;
		flag = true;
		for (int j = 1; j < N; j++) {
			if ((num[1][(i + j) % N] + M - num[0][j]) % M != K) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
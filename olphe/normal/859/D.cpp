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

long long int num[200000] = {};
vector<vector<long long int>>dp(200000, vector<long long int>(2, LLONG_MAX));



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int two[] = { 1,2,4,8,16,32,64,128 };
	long double rate[64][64] = {};
	long double point[6][64] = {};
	for (int i = 0; i < two[N]; i++) {
		for (int j = 0; j < two[N]; j++) {
			cin >> rate[i][j];
			rate[i][j] /= 100;
		}
	}
	for (int i = 0; i < two[N - 1]; i++) {
		point[0][i * 2] = rate[i * 2][i * 2 + 1];
		point[0][i * 2 + 1] = rate[i * 2 + 1][i * 2];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < two[N]; j++) {
			for (int k = 0; k < two[N]; k++) {
				if (j / two[i + 1] == k / two[i + 1] && j / two[i] != k / two[i]) {
					point[i][j] += point[i - 1][j] * point[i - 1][k] * rate[j][k];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < two[N]; j++) {
			point[i][j] *= two[i];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < two[N]; j++) {
			long double box = 0;
			for (int k = 0; k < two[N]; k++) {
				if (j / two[i + 1] == k / two[i + 1] && j / two[i] != k / two[i]) {
					box = max(point[i - 1][k],box);
				}
			}
			point[i][j] += point[i - 1][j] + box;
		}
	}
	long double ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < two[N]; j++) {
			ans = max(ans, point[i][j]);
		}
	}
	cout << setprecision(20) << ans << endl;
	return 0;
}
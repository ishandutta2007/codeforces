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

long long int N, M, K, L, R, H, W;


int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	scanf("%lld", &N);
	int num[1001][5] = {};
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	vector<bool>flag(N + 1, true);
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				int box = 0;
				int bag = 0;
				if (flag[i]) {
					for (int l = 0; l < 5; l++) {
						box += (num[j][l] - num[i][l])*(num[k][l] - num[i][l]);
						bag += abs((num[j][l] - num[i][l])*(num[k][l] - num[i][l]));
					}
					if (box > 0) {
						flag[i] = false;
					}
				}
				box = 0;
				bag = 0;
				if (flag[j]) {
					for (int l = 0; l < 5; l++) {
						box += (num[i][l] - num[j][l])*(num[k][l] - num[j][l]);
						bag += abs((num[i][l] - num[j][l])*(num[k][l] - num[j][l]));
					}
					if (box > 0) {
						flag[j] = false;
					}
				}
				box = 0;
				bag = 0;
				if (flag[k]) {
					for (int l = 0; l < 5; l++) {
						box += (num[i][l] - num[k][l])*(num[j][l] - num[k][l]);
						bag += abs((num[i][l] - num[k][l])*(num[j][l] - num[k][l]));
					}
					if (box > 0) {
						flag[k] = false;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (flag[i]) {
			M++;
		}
	}
	cout << M << endl;
	for (int i = 1; i <= N; i++) {
		if (flag[i]) {
			cout << i << endl;
		}
	}
	return 0;

}
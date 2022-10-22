#include "iostream"
#include "stdio.h"
#include "iomanip"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "string"
#include "utility"

using namespace std;

const int MOD = 1000000007;

list <int>P;
long long int box;
long long int Q;
long long int r, n;
long long int num[1000001][21];
long long int ans;
long long int bag;
bool flag;

int main() {
	num[0][0] = 1;
	for (int i = 1; i < 21; i++) {
		num[0][i] = 2;
	}
	for (int i = 0; i < 21; i++) {
		num[1][i] = i * 2 + 1;
	}
	for (int i = 2; i <= 1000000; i++) {
		num[i][0] = 1;
		for (int j = 1; j < 21; j++) {
			num[i][j] = num[i][j - 1] + num[i - 1][j];
			if(num[i][j]>=MOD)num[i][j] %= MOD;
		}
	}
	P.push_back(2);
	for (int i = 3; i <= 1000; i++) {
		flag = true;
		for (auto j = P.begin(); j != P.end(); ++j) {
			if (i%*j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			P.push_back(i);
		}
	}
	scanf("%lld", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%lld %lld", &r, &n);
		ans = 1;
		box = n;
		for (auto j = P.begin(); j != P.end(); ++j) {
			if (box ==1)break;
			if (box%*j == 0) {
				bag = 0;
				while (box%*j == 0) {
					bag++;
					box /= *j;
				}
				ans *= num[r][bag];
				if(ans>=MOD)ans %= MOD;
			}
		}
		if (box != 1) {
			ans *= num[r][1];
			if(ans>=MOD)ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
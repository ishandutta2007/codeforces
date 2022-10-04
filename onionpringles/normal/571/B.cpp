#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair((a),(b))
#define nextInt(n) scanf("%d",&(n))
#define F(i,n) for(int (i) = 0; (i) < n; (i)++)

using namespace std;
typedef long long ll;

ll dyn[5001][5001];
int A[300000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	nextInt(n); nextInt(k);
	F(i, n) nextInt(A[i]);
	sort(A, A + n);
	int rem = n%k;
	int q = n / k;
	for (int i = 0; i <= k; i++) {
		if (i == 0) {
			dyn[0][0] = 0;
			dyn[0][1] = -1;
			continue;
		}
		int j = min(i, rem);
		for (int t = 0; t <= j; t++) {
			dyn[i][t] = 2000000000;
			if (t > 0) {
				dyn[i][t] = min(dyn[i][t], dyn[i - 1][t - 1] + A[i*q + t - 1] - A[(i - 1)*q + t - 1]);
			}
			if (dyn[i - 1][t] != -1) {
				dyn[i][t] = min(dyn[i][t], dyn[i - 1][t] + A[i*q + t - 1] - A[(i - 1)*q + t]);
			}
		}
		dyn[i][j + 1] = -1;
	}
	printf("%I64d", dyn[k][rem]);
	return 0;
}
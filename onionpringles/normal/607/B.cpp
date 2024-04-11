#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

int dyn[555][555];
int dat[500];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", dat + i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			if (i == 0) dyn[j][j + i] = 1;
			else {
				dyn[j][j + i] = 1000000000;
				for (int k = j; k < j + i; k++) {
					dyn[j][j + i] = min(dyn[j][j + i], dyn[j][k] + dyn[k + 1][j + i]);
				}
				if (dat[j] == dat[j + i]) {
					if (i == 1) dyn[j][j + i] = 1;
					else {
						dyn[j][j + i] = min(dyn[j][j + i], dyn[j + 1][j + i - 1]);
					}
				}
			}
		}
	}

	printf("%d\n", dyn[0][n-1]);
}
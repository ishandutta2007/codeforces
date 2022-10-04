#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>

using namespace std;

vector<double> dyn[100];
int rnk[100];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int total = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		rnk[i] = x;
		total += x;
	}
	
	for (int i = 0; i < m; i++) {
		if (rnk[0] == i) dyn[0].push_back(0);
		else dyn[0].push_back(1.0 / (m - 1));
	}

	for (int i = 1; i < n; i++) {
		int maxind = (i + 1)*(m - 1); 
		double cursum = 0;
		for (int j = 0; j < m; j++) {
			cursum += dyn[i - 1][j];
			double tmp = 0;
			if (j>=rnk[i]) {
				tmp = dyn[i - 1][j - rnk[i]];
			}
			cursum -= tmp;
			dyn[i].push_back(cursum / (m - 1));
			cursum += tmp;
		}
		for (int j = m; j <=maxind-m+1; j++) {
			cursum += dyn[i-1][j];
			cursum -= dyn[i - 1][j - m];
			double tmp = dyn[i-1][j-rnk[i]];
			cursum -= tmp;
			dyn[i].push_back(cursum / (m - 1));
			cursum += tmp;
		}
		for (int j = maxind - m + 2; j <= maxind; j++) {
			cursum -= dyn[i - 1][j - m];
			double tmp = 0;
			if (rnk[i] >= m + j - maxind - 1) {
			//	printf("hi\n");
				tmp = dyn[i - 1][j - rnk[i]];
			}
			cursum -= tmp;
			dyn[i].push_back(cursum / (m - 1));
			cursum += tmp;
		}
	/*	for (auto &x : dyn[i]) {
			printf("%f ", x);
		}
		printf("\n");*/
	}
	double totalp = 0;
	for (int i = 0; i < total; i++) {
		totalp += dyn[n - 1][i];
	}
	printf("%.15f", 1 + totalp*(m - 1));
}
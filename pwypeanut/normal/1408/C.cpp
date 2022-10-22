#include <bits/stdc++.h>
using namespace std;

int TC, N, L, A[100005];
double timl[100005], timr[100005];

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &N, &L);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		double tim = 0;
		timl[0] = 0;
		for (int i = 0; i < N; i++) {
			long long dis = A[i] - ((i == 0) ? 0 : A[i - 1]);
			tim += (double)dis / (i + 1);
			timl[i + 1] = tim;
		}
		tim += (double)(L - A[N - 1]) / (N + 1);
		timl[N + 1] = tim;
		
		tim = 0;
		timr[N + 1] = 0;
		for (int i = 0; i < N; i++) {
			long long dis = ((i == 0) ? L : A[N - i]) - A[N - i - 1];
			tim += (double)dis / (i + 1);
			timr[N - i] = tim;
		}
		tim += (double)A[0] / (N + 1);
		timr[0] = tim;
		
		int lastpoint = 0;
		for (int i = 0; i <= N + 1; i++) {
			if (timl[i] <= timr[i]) lastpoint = i;
		}
		
		//for (int i = 0; i < N + 2; i++) printf("timl[%d] = %Lf\n", i, timl[i]);
		//for (int i = 0; i < N + 2; i++) printf("timr[%d] = %Lf\n", i, timr[i]);
		
		if (lastpoint == N + 1) {
			printf("0\n");
			continue;
		}
		
		double ans;
		int leftpoint = ((lastpoint == 0) ? 0 : A[lastpoint - 1]);
		int rightpoint = ((lastpoint == N) ? L : A[lastpoint]);
		int rightspeed = (N + 1 - lastpoint);
		int leftspeed = lastpoint + 1;
		//printf("%d %d %d %d\n", leftpoint, rightpoint, rightspeed, leftspeed);
		if (timl[lastpoint] < timr[lastpoint + 1]) {
			ans = timr[lastpoint + 1] + ((double)(rightpoint - leftpoint) - (timr[lastpoint + 1] - timl[lastpoint]) * leftspeed) / (leftspeed + rightspeed);
		} else {
			ans = timl[lastpoint] + ((double)(rightpoint - leftpoint) - (timl[lastpoint] - timr[lastpoint + 1]) * rightspeed) / (leftspeed + rightspeed);
		}
		printf("%.10lf\n", ans);
	}
}
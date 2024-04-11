#include <bits/stdc++.h>
using namespace std;

int N;
double mx[100005], mn[100005], a[100005], b[100005];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lf", &mx[i]);
	for (int i = 0; i < N; i++) scanf("%lf", &mn[i]);
	for (int i = 1; i < N; i++) {
		mx[i] += mx[i - 1];
		mn[i] += mn[i - 1];
	}
	for (int i = 0; i < N; i++) {
		double x = mx[i], y = mn[i];
		b[i] = ((x + y) + sqrt(max(0.0, (x + y) * (x + y) - 4.0 * x))) / 2;
		a[i] = x + y - b[i];
	}
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%.7lf", a[i] - ((i == 0) ? 0 : a[i - 1]));
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%.7lf", b[i] - ((i == 0) ? 0 : b[i - 1]));
	}
	printf("\n");
}
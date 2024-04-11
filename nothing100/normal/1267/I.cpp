#include <bits/stdc++.h>
using namespace std;
 
int n, N;
int a[105], b[105];
char opt;
 
int main() {
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		scanf("%d", &n);
		N = n * 2;
		for (int i = 1; i <= n; ++ i) {
			printf("? %d %d\n", 2 * i - 1, 2 * i);
			fflush(stdout);
			char opt; scanf("\n%c", &opt);
			if (opt == '>') {
				a[i] = 2 * i;
				b[i] = 2 * i - 1;
			} else {
				a[i] = 2 * i - 1;
				b[i] = 2 * i;
			}
		}
		
		for (int i = 1; i <= n; ++ i) {
			for (int j = i + 1; j <= n; ++ j) {
				printf("? %d %d\n", a[i], a[j]);
				fflush(stdout);
				char opt; scanf("\n%c", &opt);
				if (opt == '>') {
					swap(a[i], a[j]);
					swap(b[i], b[j]);
				}
			}
		}
		
		printf("? %d %d\n", a[n - 1], b[n - 2]);
		fflush(stdout);
		scanf("\n%c", &opt);
		if (opt == '<') {
			printf("? %d %d\n", b[n - 1], b[n - 2]);
			fflush(stdout);
			scanf("\n%c", &opt);
			if (opt == '<') {
				swap(b[n - 1], b[n - 2]);
			}
		}

		for (int i = 1; i <= n - 2; ++ i) {
			for (int j = 1; j <= n; ++ j) {
//				if (i == j) continue;
				printf("? %d %d\n", b[i], a[j]);
				fflush(stdout);
				char opt; scanf("\n%c", &opt);
			}
		}
	
		for (int i = 1; i <= n - 2; ++ i)
			for (int j = i + 1; j <= n - 2; ++ j) {
				printf("? %d %d\n", b[i], b[j]);
				fflush(stdout);
				char opt; scanf("\n%c", &opt);
			}
	
		printf("? %d %d\n", a[n], a[n - 1]);
		fflush(stdout);
		char opt; scanf("\n%c", &opt);
		printf("!\n");
		fflush(stdout);
		
	}
	return 0;
}
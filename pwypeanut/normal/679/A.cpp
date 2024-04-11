#include <bits/stdc++.h>
using namespace std;

int arr[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
	int ans, cnt = 0;
	for (int i = 2; i <= 10; i++) {
		printf("%d\n", i);
		fflush(stdout);
		string s;
		cin >> s;
		if (s == "yes") {
			ans = i;
			cnt++;
		}
	}
	if (cnt == 0) {
		printf("prime\n");
	} else if (cnt > 1) {
		printf("composite\n");
	} else {
		if (ans * ans > 10) {
			printf("%d\n", ans * ans);
			fflush(stdout);
			string s;
			cin >> s;
			if (s == "yes") {
				printf("composite\n");
				return 0;
			}
		}
		for (int i = 0; i < 11; i++) {
			if (arr[i] * ans <= 100) {
				printf("%d\n", arr[i]);
				fflush(stdout);
				string s;
				cin >> s;
				if (s == "yes") {
					printf("composite\n");
					return 0;
				}
			}
		}
		printf("prime\n");
	}
}
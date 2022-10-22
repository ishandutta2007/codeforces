#include <bits/stdc++.h>
using namespace std;

long long K;
string cf = "codeforces";

int main() {
	scanf("%lld", &K);
	for (int i = 1; i < 100; i++) {
		for (int j = 0; j <= 10; j++) {
			long long ans = 1;
			for (int k = 0; k < j; k++) ans *= (i+1);
			for (int k = 0; k < 10 - j; k++) ans *= i;
			if (ans >= K) {
				for (int k = 0; k < j; k++) {
					for (int l = 0; l < i+1; l++) printf("%c", cf[k]);
				}
				for (int k = j; k < 10; k++) {
					for (int l = 0; l < i; l++) printf("%c", cf[k]);
				}
				return 0;
			}
		}
	}
}
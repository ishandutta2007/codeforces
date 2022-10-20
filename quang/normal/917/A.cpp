#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

char s[N];
int n;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int mn = 0, mx = 0;
		for (int j = i; j <= n; j++) {
			if (s[j] == '(') {
				mx++;
				mn++;
			} else if (s[j] == ')') {
				mn--;
				if (mn < 0) {
					mn = 1;
				}
				mx--;
			} else {
				mx++;
				if (mn == 0) {
					mn = 1;
				} else {
					mn--;
				}
			}
			if (mx < 0) {
				break;
			}
			if (mn == 0) {
				res++;
			}
		}
	}	
	cout << res << endl;
	return 0;
}
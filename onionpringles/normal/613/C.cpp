#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#define mp(a,b) make_pair(a,b)
#define ni(a) scanf("%d", &(a))
#define F(i,n) for(int (i) = 0; (i) < (n); (i)++)

using namespace std;
typedef pair<int, int> pii;

int a[26];
int b[26];
char buf[100001];
int sum = 0;
int n;
vector<int> divs;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int ispos(int sum) {
	if (sum % 2 == 0) {
		F(i, n) {
			if (b[i] % 2 != 0) return 0;
		}
		return 1;
	}
	else {
		int ocnt = 0;
		F(i, n) {
			if (b[i] % 2 != 0) {
				if (!ocnt) ocnt = 1;
				else return 0;
			}
		}
		return 1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ni(n);
	F(i, n) ni(a[i]);
	int g = a[0]; // number of blocks
	F(i, n) {
		g = gcd(g, a[i]);
		sum += a[i];
	}
	int i;
	for (i = 1; i <= g; i++) {
		if (g%i == 0) divs.push_back(i);
	}
	int ans = 0;
	int ind = -1;
	for (auto &x : divs) {
		int T = sum / x;
		F(i, n) {
			b[i] = a[i] / x;
		}
		if (ispos(T)) {
			if (T % 2 == 0) {
				if (ans < 2 * x) {
					ans = 2 * x;
					ind = x;
				}
			}
			else {
				if (ans < x) {
					ans = x;
					ind = x;
				}
			}
		}
	}
	if (ans == 0) {
		puts("0");
		F(i, n) {
			F(j, a[i]) {
				printf("%c", 'a' + i);
			}
		}
	}
	else {
		printf("%d\n", ans);
		int T = sum / ind;
		F(i, n) a[i] /= ind;
		if (T % 2 == 0) {
			int j = 0;
			F(i, n) {
				F(k, a[i] / 2 ) {
					buf[j] = 'a' + i;
					buf[T - 1 - j] = 'a' + i;
					j++;
				}
			}
		}
		else {
			int j = 0;
			F(i, n) {
				if (a[i] % 2 == 0) {
					F(k, a[i] / 2) {
						buf[j] = 'a' + i;
						buf[T - 1 - j] = 'a' + i;
						j++;
					}
				}
				else {
					int mid = T / 2;
					for (int k = mid - a[i] / 2; k <= mid + a[i] / 2; k++) {
						buf[k] = 'a' + i;
					}
				}
			}
		}
		F(i, ind) {
			printf("%s", buf);
		}
	}
	return 0;
}
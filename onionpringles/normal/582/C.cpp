#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[200000];
int block[400000];
int dyn[400000];
ll saved[200000];
int badcnt[200001];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int phi(int m) {
	if (m == 1) return 1;
	int tmp = m;
	int res = m;
	for (int i = 2; i*i <= tmp; i++) {
		if (tmp%i == 0) {
			m /= i;
			m *= (i - 1);
			while (tmp%i == 0) tmp /= i;
		}
	}
	if (tmp > 1) return m - 1;
	else return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	ll total = 0;
	for (int i = 1; i < n; i++) {
		if (n%i != 0) {
			continue;
		}
		int num = n / i;
		badcnt[1] = 1;
		for (int j = 2; j <= num; j++) badcnt[j] = 1;
		for (int j = 2; j <= num; j++) {
			if (num%j == 0) {
				for (int k = j; k <= num; k += j) {
					badcnt[k] = 0;
				}
			}
		}
		for (int j = 2; j <= num; j++) {
			badcnt[j] += badcnt[j - 1];
		}
		memset(block, 0, sizeof(block));
		for (int j = 0; j < i; j++) {
			int maxel = 0;
			for (int k = 0; k < num; k++) {
				maxel = max(maxel, a[k*i + j]);
			}
			for (int k = 0; k < num; k++) {
				if (a[k*i + j] == maxel) {
					block[k*i + j] = 1;
					block[n + k*i + j] = 1;
				}
			}
		}
		for (int j = 0; j < 2 * n; j++) {
			dyn[j] = block[j];
			if (dyn[j] && j > 0) dyn[j] += dyn[j - 1];
		}
		ll cnt = 0;
		for (int j = n; j < 2 * n; j++) {
			if (dyn[j] >= i) {
				dyn[j] = min(dyn[j], n);
				cnt += badcnt[dyn[j] / i];
			}
		}
		saved[i] = cnt;
		total += cnt;
	}
	printf("%I64d", total);
	return 0;
}
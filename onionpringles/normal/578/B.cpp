#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 200000;

int prefix[MN];
int suffix[MN];
int a[MN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	long long res = 1;
	for (int i = 0; i < k; i++) res *= x;

	prefix[0] = 0;
	for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] | a[i-1];
	suffix[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] | a[i+1];

	long long maxval = -1;
	for (int i = 0; i < n; i++) {
		maxval = max(maxval, (long long)prefix[i] | suffix[i] | ((long long)res*a[i]));
	}
	printf("%I64d\n", maxval);

	return 0;
}
#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

int w[2000000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	memset(w, 0, sizeof(w));
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		w[x]++;
	}
	int cnt = 0;
	for (int i = 0; i < 2000000-1; i++) {
		cnt += w[i] % 2;
		w[i + 1] += w[i] / 2;
	}
	printf("%d\n", cnt);
	return 0;
}
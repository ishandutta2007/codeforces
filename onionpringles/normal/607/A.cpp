#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

pii bc[100000];
int dyn[100000];

int bs(int n, int a) {
	int l = 0; int u = n;
	while (l!=u) {
		int m = (l + u) / 2;
		if (bc[m].first < a) l = m + 1;
		else u = m;
	}
	return l;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		bc[i] = mp(x, y);
	}
	sort(bc, bc + n);
	dyn[0] = 1;
	for (int i = 1; i < n; i++) {
		int j = bs(i, bc[i].first - bc[i].second);
		if (j == 0) {
			dyn[i] = 1;
		}
		else {
			dyn[i] = dyn[j - 1]+1;
		}
	}

	printf("%d\n", n- (*max_element(dyn, dyn + n)) );
}
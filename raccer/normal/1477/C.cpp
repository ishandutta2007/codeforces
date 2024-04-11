#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[5010];
int id[5010];

pii operator - (const pii &A, const pii &B) {
	return mp(A.fi - B.fi, A.se - B.se);
}

long long operator * (const pii &A, const pii &B) {
	return 1ll * A.fi * B.fi + 1ll * A.se * B.se;
}

bool OK(pii x, pii y, pii z) {
	return (x - y) * (z - y) > 0;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].fi, &a[i].se);
		id[i] = i;
	}
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = n - 3; i >= 0; i--) {
			if (OK(a[i], a[i + 1], a[i + 2])) continue;
			int j = i;
			while (j + 2 < n && !OK(a[j], a[j + 1], a[j + 2])) swap(a[j], a[j + 1]), swap(id[j], id[j + 1]), j++;
			flag = 1;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", id[i] + 1);
	}
	printf("\n");
	return 0;
}
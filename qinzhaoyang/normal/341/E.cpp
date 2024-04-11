#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N], p1, p2 = 1, p3 = 2;
vector <pair<int,int> > ans;

void ope(int x, int y) {
	a[y] -= a[x], a[x] *= 2;
	ans.push_back(make_pair(x, y));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 3; i <= n; i++)
		for (p1 = i; ; ){
			if (a[p1] > a[p2]) swap(p1, p2);
			if (a[p2] > a[p3]) swap(p2, p3);
			if (a[p1] > a[p3]) swap(p1, p3);
			if (a[p1] == 0) break;
			for (int j = a[p2] / a[p1]; j; j >>= 1)
				if (j & 1) ope(p1, p2); else ope(p1, p3);
		}
	if ((a[p1] == 0) + (a[p2] == 0) + (a[p3] == 0) == 1) {
		printf("%d\n", (int)ans.size());
		for (pair<int,int> pr : ans) printf("%d %d\n", pr.first, pr.second);
	}
	else puts("-1");
	return 0;
}
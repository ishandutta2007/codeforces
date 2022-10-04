#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(n), &(m))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> pos;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	ni(n);
	for (int i = 0; i < n; i++) {
		int x;
		ni(x);
		if(x==1) pos.push_back(i);
	}
	if (pos.empty()) {
		puts("0"); return 0;
	}
	int sz = pos.size();
	ll ans = 1;
	for (int i = 1; i < sz; i++) {
		ans *= pos[i] - pos[i - 1];
	}
	printf("%I64d", ans);

	return 0;
}
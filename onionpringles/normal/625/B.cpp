#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char buf[100001];
char buf2[31];

vector<pii> inter;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s %s", buf, buf2);
	int l1 = strlen(buf);
	int l2 = strlen(buf2);
	if (l2 > l1) {
		puts("0"); return 0;
	}
	for (int i = 0; i + l2 <= l1; i++) {
		if (strncmp(buf + i, buf2, l2) == 0) {
			inter.push_back(make_pair(i, i + l2 - 1));
		}
	}
	int cur = -1;
	sort(inter.begin(), inter.end(), [](const pii& x, const pii& y) {
		return x.second < y.second;
	});
	int cnt = 0;
	for (auto &x : inter) {
		if (x.first <= cur) continue;
		else {
			cur = x.second;
			cnt++;
		}
	}
	printf("%d\n", cnt);
}
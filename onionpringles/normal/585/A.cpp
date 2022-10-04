#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int valid[4000];
int v[4000];
int d[4000];
long long p[4000];
vector<int> ans;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) scanf("%d %d %I64d", v + i, d + i, p + i);
	for (int i = 0; i < n; i++) {
		valid[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!valid[i]) continue;
		ans.push_back(i + 1);
		cnt++;
		int vcnt = 0;
		for (int j = i + 1; j < n && vcnt < v[i];) {
			if (!valid[j]) {
				j++;
				continue;
			}
			p[j] -= (v[i] - vcnt);
			if (p[j] < 0) valid[j] = -1;
			vcnt++;
			j++;
		}
		long long sumd = 0;
		for (int j = i + 1; j < n; j++) {
			if (!valid[j]) continue;
			p[j] -= sumd;
			if (p[j] < 0) valid[j] = -1;
			if (valid[j] == -1) {
				sumd += d[j];
				valid[j] = 0;
			}
		}
	}
	printf("%d\n", cnt);
	for (auto &x : ans) printf("%d ", x);
}
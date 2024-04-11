#pragma warning(disable:4996)
#include <stdio.h>

#include <vector>
#include <algorithm>
#include <set>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int mod = 1000000007;
const int inf = 1000000000;

vector<pii> queries;
int l[100000];
int r[100000];
int seq[100000];
pii sorted[100000];
set<int> block;

inline int abs2(int x) {
	if (x < 0) x = -x;
	return x;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	int cur;
	scanf("%d ", &cur);
	for (int i = 0; i < n-1; i++) {
		int x;
		scanf("%d", &x);
		int dx = abs2(x - cur);
		cur = x;
		seq[i] = dx;
		sorted[i] = mp(dx,i);
	}
	sort(sorted, sorted + (n - 1));
	for (int i = n - 2; i >= 0; i--) {
		int j = sorted[i].second;
		auto it = block.upper_bound(j);
		if (it == block.end()) {
			r[j] = n - 2;
			if (it == block.begin()) {
				l[j] = 0;
			}
			else {
				it--;
				l[j] = (*it)+1;
			}
		}
		else {
			r[j] = (*it)-1;
			if (it == block.begin()) {
				l[j] = 0;
			}
			else {
				it--;
				l[j] = (*it)+1;
			}
		}
		block.insert(j);
	}

	for (int i = 0; i < q; i++) {
		int ql, qr;
		long long res = 0;
		scanf("%d %d ", &ql, &qr);
		ql--; qr -= 2;
		for (int j = ql; j <= qr; j++) {
			int left = max(ql, l[j]);
			int right = min(qr, r[j]);
			LL tmp = (LL)(right - j + 1)*(j - left + 1)*seq[j];
			res += tmp;
		}
		printf("%I64d\n", res);
	}


	return 0;
}
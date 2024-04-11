#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 100000;

char buf[MN + 4];

vector<pii> mtlr;
int mtcnt[MN];
int rcnt[MN];
int lcnt[MN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", buf);
	ll ans = (ll)n*n*m;

	int avk = 0; int curl = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || buf[i] == buf[i - 1]) {
			mtcnt[avk]++;
		}
		else {
			avk++;
			mtcnt[avk]++;
			mtlr.push_back(mp(curl, i - 1));
			curl = i;
		}
	}
	mtlr.push_back(mp(curl, n - 1));
	avk++;

	ans -= ((ll)n*n + (ll)(avk - 1)*n - (ll)(avk)*(avk - 1));
	ans -= (ll)(n - avk)*((m - 1)*n - (avk - 1));

	int i = 0;
	while (i < n - 1) {
		int x = buf[i];
		int y = buf[i + 1];
		if (x == y) {
			i++;
			continue;
		}
		int cnt = 0;
		while (buf[i + cnt] + buf[i + cnt + 1] == x + y) {
			cnt++;
		}
		ans -= (ll)cnt*(cnt + 1) / 2;
		i = i + cnt;
	}

	printf("%I64d", ans);

	return 0;
}
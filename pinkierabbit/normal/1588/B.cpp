#include <cstdio>

typedef long long LL;

int Ask(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	LL ret;
	scanf("%lld", &ret);
	return ret;
}

void Solve() {
	int N;
	scanf("%d", &N);
	LL tot = Ask(1, N);
	int tr = N;
	{ // 30
		int lb = 4, rb = N - 1;
		while (lb <= rb) {
			int mid = (lb + rb) / 2;
			if (Ask(1, mid) == tot) tr = mid, rb = mid - 1;
			else lb = mid + 1;
		}
	}
	int lenr = (int)(tot - Ask(1, tr - 1) + 1);
	int tmid = tr - lenr + 1;
	int lenl = (int)(Ask(1, tmid - 1) - Ask(1, tmid - 2) + 1);
	int tl = tmid - lenl;
	printf("! %d %d %d\n", tl, tmid, tr);
	fflush(stdout);
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--)
		Solve();
	return 0;
}
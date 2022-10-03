#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int Inf = 0x3f3f3f3f;

int x[4], y[4], Ans, ax[4], ay[4];
int lx[4], xy[4][5], ly[4], yx[4][5], cx, cy;

int p[4], bx[4], by[4];
inline void chk2() {
	int d01 = abs(bx[0] == bx[1] ? by[0] - by[1] : bx[0] - bx[1]);
	int d02 = abs(bx[0] == bx[2] ? by[0] - by[2] : bx[0] - bx[2]);
	int d31 = abs(bx[3] == bx[1] ? by[3] - by[1] : bx[3] - bx[1]);
	int d32 = abs(bx[3] == bx[2] ? by[3] - by[2] : bx[3] - bx[2]);
	if (d01 != d02 || d02 != d31 || d31 != d32) return ;
	do {
		int mx = 0;
		for (int i = 0; i < 4; ++i) {
			if (x[i] != bx[p[i]] && y[i] != by[p[i]]) { mx = Inf; break; }
			if (x[i] == bx[p[i]]) mx = std::max(mx, abs(y[i] - by[p[i]]));
			else mx = std::max(mx, abs(x[i] - bx[p[i]]));
		}
		if (mx < Ans) {
			Ans = mx;
			for (int i = 0; i < 4; ++i) ax[i] = bx[p[i]], ay[i] = by[p[i]];
		}
	} while (std::next_permutation(p, p + 4));
}
inline void check() {
	if (cx == 2 && cy == 2) {
		bx[0] = lx[0], by[0] = ly[0];
		bx[1] = lx[0], by[1] = ly[1];
		bx[2] = lx[1], by[2] = ly[0];
		bx[3] = lx[1], by[3] = ly[1];
		chk2();
	} else if (cy == 1) {
		bx[0] = lx[0], by[0] = ly[0];
		bx[1] = lx[1], by[1] = ly[0];
		bx[2] = lx[0], by[2] = ly[0] + (lx[0] - lx[1]);
		bx[3] = lx[1], by[3] = ly[0] + (lx[0] - lx[1]);
		chk2();
		bx[2] = lx[0], by[2] = ly[0] - (lx[0] - lx[1]);
		bx[3] = lx[1], by[3] = ly[0] - (lx[0] - lx[1]);
		chk2();
	} else if (cx == 1) {
		bx[0] = lx[0], by[0] = ly[0];
		bx[1] = lx[0], by[1] = ly[1];
		bx[2] = lx[0] + (ly[0] - ly[1]), by[2] = ly[0];
		bx[3] = lx[0] + (ly[0] - ly[1]), by[3] = ly[1];
		chk2();
		bx[2] = lx[0] - (ly[0] - ly[1]), by[2] = ly[0];
		bx[3] = lx[0] - (ly[0] - ly[1]), by[3] = ly[1];
		chk2();
	} else if (cy == 0) {
		int d = abs(lx[0] - lx[1]);
		std::sort(xy[0] + 1, xy[0] + 3);
		std::sort(xy[1] + 1, xy[1] + 3);
		int a[4] = {xy[0][1], xy[0][2] - d, xy[1][1], xy[1][2] - d};
		std::sort(a, a + 4);
		int z = (a[0] + a[3]) / 2;
		bx[0] = lx[0], by[0] = z;
		bx[1] = lx[0], by[1] = z + d;
		bx[2] = lx[1], by[2] = z;
		bx[3] = lx[1], by[3] = z + d;
		chk2();
	} else {
		int d = abs(ly[0] - ly[1]);
		std::sort(yx[0] + 1, yx[0] + 3);
		std::sort(yx[1] + 1, yx[1] + 3);
		int a[4] = {yx[0][1], yx[0][2] - d, yx[1][1], yx[1][2] - d};
		std::sort(a, a + 4);
		int z = (a[0] + a[3]) / 2;
		bx[0] = z, by[0] = ly[0];
		bx[1] = z + d, by[1] = ly[0];
		bx[2] = z, by[2] = ly[1];
		bx[3] = z + d, by[3] = ly[1];
		chk2();
	}
}

int main() {
	for (int i = 0; i < 4; ++i) p[i] = i;
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		Ans = Inf;
		for (int i = 0; i < 4; ++i) scanf("%d%d", &x[i], &y[i]);
		for (int S = 0; S < 16; ++S) {
			cx = cy = 0;
			for (int i = 0; i < 4; ++i)
				if (S >> i & 1) {
					int o = -1;
					for (int j = 0; j < cx; ++j) if (lx[j] == x[i]) o = j;
					if (~o) xy[o][++*xy[o]] = y[i];
					else xy[cx][*xy[cx] = 1] = y[i], lx[cx++] = x[i];
				} else {
					int o = -1;
					for (int j = 0; j < cy; ++j) if (ly[j] == y[i]) o = j;
					if (~o) yx[o][++*yx[o]] = x[i];
					else yx[cy][*yx[cy] = 1] = x[i], ly[cy++] = y[i];
				}
			if (std::max(cx, cy) != 2 || (cy == 0 && *xy[0] != 2) || (cx == 0 && *yx[0] != 2)) continue;
			check();
		}
		if (Ans == Inf) { puts("-1"); continue; }
		printf("%d\n", Ans);
		for (int i = 0; i < 4; ++i)
			printf("%d %d\n", ax[i], ay[i]);
	}
	return 0;
}
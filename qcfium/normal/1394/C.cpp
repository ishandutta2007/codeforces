#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

#define INF 1000000000

int main() {
	int n = ri();
	std::pair<int, int> a[n];
	{
		char buf[500001];
		for (auto &i : a) {
			scanf("%s", buf);
			int r0 = 0, r1 = 0;
			for (char *s = buf; *s; s++) {
				if (*s == 'B') r0++;
				else r1++;
			}
			i = {r0, r1};
		}
	}
	int l = -1;
	int r = 500001;
	std::pair<int, int> last_ok = {-1, -1};
	while (r - l > 1) {
		int m = l + ((r - l) >> 1);
		
		int x0 = 0;
		int x1 = INF;
		int y0 = 0;
		int y1 = INF;
		int x_y_0 = -INF;
		int x_y_1 = INF;
		for (auto i : a) {
			x0 = std::max(x0, i.first - m);
			x1 = std::min(x1, i.first + m);
			y0 = std::max(y0, i.second - m);
			y1 = std::min(y1, i.second + m);
			x_y_0 = std::max(x_y_0, i.first - i.second - m);
			x_y_1 = std::min(x_y_1, i.first - i.second + m);
		}
		x_y_0 = std::max(x_y_0, x0 - y1);
		x_y_1 = std::min(x_y_1, x1 - y0);
		
		/*
		if (m == 1) {
			std::cerr << "m1 info :" << std::endl;
			std::cerr << x0 << " " << x1 << std::endl;
			std::cerr << y0 << " " << y1 << std::endl;
			std::cerr << x_y_0 << " " << x_y_1 << std::endl;
			std::cerr << std::endl;
		}*/
		if (x0 > x1 || y0 > y1 || x_y_0 > x_y_1) l = m;
		else {
			if (x0 - y0 < x_y_0) last_ok = {x0 + (x_y_0 - (x0 - y0)), y0};
			else if (x0 - y0 > x_y_1) last_ok = {x0, y0 + (x0 - y0 - x_y_1)};
			else if (x0 || y0) last_ok = {x0, y0};
			else if (x0 - y0 < x_y_1) last_ok = {x0 + 1, y0};
			else if (x0 - y0 > x_y_0) last_ok = {x0, y0 + 1};
			else if (x0 < x1 && y0 < y1) last_ok = {x0 + 1, y0 + 1};
			else {
				l = m;
				continue;
			}
			r = m;
		}
	}
	printf("%d\n", r);
	
	// std::cerr << last_ok.first <<" " << last_ok.second << std::endl;
	for (int i = 0; i < last_ok.first; i++) printf("B");
	for (int i = 0; i < last_ok.second; i++) printf("N");
	puts("");
	
	return 0;
}
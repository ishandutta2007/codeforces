#include <stdio.h>
#include <algorithm>

using namespace std;

int y1, y2, y3;
int m1, m2, m3;
int h, a, d;
int ans = (-1u/2);

int main() {
	scanf("%d%d%d", &y1, &y2, &y3);
	scanf("%d%d%d", &m1, &m2, &m3);
	scanf("%d%d%d", &h, &a, &d);
	
	for(int i = 0;!i || y3 + i <= m2;i++) {
		for(int j = 0;!j || y2 + j - m3 <= m1; j++) {
			if(y2 + j <= m3) {
				continue;
			}
			int desc = y2 + j - m3;
			int round = (m1 + desc-1) / desc;
			int y_min_hp = round * max(0, m2 - (y3 + i)) + 1;
			int inc_hp = max(0, y_min_hp - y1);
			int val = i * d + j * a + inc_hp * h;
			if(val < ans) {
				ans = val;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
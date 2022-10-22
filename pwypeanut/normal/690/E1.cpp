#include <bits/stdc++.h>
using namespace std;

int Q, H, W, a[606][605];

int f(int x, int y) {
	return max(x, y) * max(x, y) - min(x, y) * min(x, y);
}

int main() {
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &H, &W);
		for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) scanf("%d", &a[i][j]);
		int contrast = 0, con2 = 0;
		for (int i = 0; i < W; i++) contrast += f(a[H/2-1][i], a[H/2][i]);
		for (int i = 0; i < W; i++) con2 += f(a[H-1][i], a[0][i]);
		//printf("%d %d\n", contrast, con2);
		if (contrast < con2) printf("NO\n");
		else printf("YES\n");
	}
}
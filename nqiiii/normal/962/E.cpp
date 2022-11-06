#include <bits/stdc++.h>
using namespace std; 
#define int long long
const int maxN = 300000, inf = 1e18;
int a[maxN + 10], n; char c[maxN + 10]; 
int b[maxN + 10], bCnt, maxR, minR = inf, maxB, minB = inf, ans; 
main() {
	scanf("%lld", &n); 
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]); 
		for (c[i] = getchar(); !isgraph(c[i]); c[i] = getchar()); 
		if (c[i] == 'P') b[++bCnt] = i; 
		else if (c[i] == 'R') {
			maxR = max(maxR, a[i]);  minR = min(minR, a[i]); 
		}else if (c[i] == 'B') {
			maxB = max(maxB, a[i]);  minB = min(minB, a[i]); 
		}
	}
	if (bCnt == 0) {
		if (maxR) ans += maxR - minR; 
		if (maxB) ans += maxB - minB; 
	}else {
		if (minR < a[b[1]]) ans += a[b[1]] - minR; 
		if (maxR > a[b[bCnt]]) ans += maxR - a[b[bCnt]]; 
		if (minB < a[b[1]]) ans += a[b[1]] - minB; 
		if (maxB > a[b[bCnt]]) ans += maxB - a[b[bCnt]]; 
		for (int i = 1; i < bCnt; ++i) {
			int prer = a[b[i]], preb = a[b[i]], maxR = 0, maxB = 0; 
			for (int j = b[i] + 1; j < b[i + 1]; ++j)
				if (c[j] == 'R') {
					maxR = max(maxR, a[j] - prer);  prer = a[j]; 
				}else {
					maxB = max(maxB, a[j] - preb);  preb = a[j]; 
				}
			maxR = max(maxR, a[b[i + 1]] - prer);  maxB = max(maxB, a[b[i + 1]] - preb); 
			if (maxR + maxB > a[b[i + 1]] - a[b[i]]) ans += (a[b[i + 1]] - a[b[i]]) * 3ll - maxR - maxB; 
			else ans += (a[b[i + 1]] - a[b[i]]) * 2; 
		}
	}
	printf("%lld", ans); 
}
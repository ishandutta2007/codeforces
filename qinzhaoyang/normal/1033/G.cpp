#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 2e5 + 10;

typedef long long ll;

int n, m, f1[2 * M], f2[2 * M], f3[2 * M]; ll v[N], ans3, ans4;

int vec[N * 5];

int all = 0;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &v[i]);
	for (int s = 2; s <= 2 * m; s++) {
		{
			// a : 1 -> (s - 1) / 2, b : s - 1 -> (s - 1) / 2 + 1
			// 1 : b <= v, 2 : 2 * a <= v, 3 : a <= v < b
			int ct = 0;
			int lst = max(s - m, 1);
			int c1 = 0, c2 = 0, c3 = 0; int mx = 0;
			for (int i = 1; i <= n; i++) {
				int t = v[i] % s;
				if (!t) continue;
				if (s - t > lst) {
					if (s - t <= (s - 1) / 2) {
						if (!(f1[s - t] || f2[s - t] || f3[s - t])) vec[++ct] = s - t;
						f1[s - t]++;
					}
				}
				else c1++;
				c2++;
				if (t / 2 + 1 > lst) {
					int tmp = t / 2 + 1;
					if (tmp <= (s - 1) / 2) {
						if (!(f1[tmp] || f2[tmp] || f3[tmp])) vec[++ct] = tmp;
						f2[tmp]++;
					}
				}
				else c2--;
				mx = max(min(t, s - t - 1) + 1, mx);
				/*
				c3++;
				if (min(t, s - t - 1) + 1 > lst) {
					int tmp = min(t, s - t - 1) + 1;
					if (tmp <= (s - 1) / 2) {
						if (!(f1[tmp] || f2[tmp] || f3[tmp])) vec[++ct] = tmp;
						f3[tmp]++;
					}
				}
				else c3--;*/
			}
			if (lst < mx && (!f1[mx] && !f2[mx] && !f3[mx])) vec[++ct] = mx;
			if (lst < mx && mx <= (s - 1) / 2) f3[mx]++;
			if (lst < mx) c3++;
			sort (vec + 1, vec + ct + 1);
			int ta1 = 0, ta2 = 0;
			for (int k = 1; k <= ct; k++) {
				int x = vec[k];
				if (x > (s - 1) / 2) break;
				if (x == vec[k - 1]) continue;
				if (lst < x) {
					int len = x - lst;
					if (c2 <= 1 && !c3 && (c1 & 1))
						ta1 += len;
					if ((!(c1 & 1)) && !c2 && !c3)
						ta2 += len;
				}
				c1 += f1[x], c2 -= f2[x], c3 -= f3[x];
				if (x > lst) lst = x;
			}
			if (lst <= (s - 1) / 2) {
				int len = (s - 1) / 2 + 1 - lst;
				if (c2 <= 1 && !c3 && (c1 & 1))
					ta1 += len;
				if ((!(c1 & 1)) && !c2 && !c3)
					ta2 += len;
			}
			ans3 += 2 * ta1, ans4 += 2 * ta2;
			for (int i = 1; i <= ct; i++) {
				int tmp = vec[i];
				f1[tmp] = f2[tmp] = f3[tmp] = 0;
			}
		}
		if (s % 2 == 0) {
			int c = 0;
			for (int i = 1; i <= n; i++) {
				int t = v[i] % s;
				if (t >= s / 2) c++;
			}
			if (c % 2 == 1) ans3++;
			else ans4++;
		}
	}
	ll ans1 = (1ll * m * m - ans3 - ans4) / 2;
	printf("%lld %lld %lld %lld\n", ans1, ans1, ans3, ans4);
	return 0;
}
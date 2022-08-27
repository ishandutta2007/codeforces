#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
using namespace std;
const int N = 707;
int n, a[N], st[N << 4], p[N << 4], tot, cnt;
vector<int> ve[N], YS[N];
bool vis[N][N], us[N];
bool f[N][N][2];
int query(int x) {
	int L = 1, R = cnt, ans = 1;
	while(L <= R) {
		int mid = (L + R) / 2;
		if(p[mid] <= x) ans = mid, L = mid + 1;
		else R = mid - 1;
	}
	return ans;
}
int gcd(int x, int y) { return x == 0 ? y : gcd(y % x, x); }
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, n) L(j, i, n) vis[i][j] = (gcd(a[i], a[j]) != 1 ? 1 : 0);
	L(len, 1, n) {
		L(l, 1, n - len + 1) {
			int r = l + len - 1;
			L(k, l, r) if((k == l || f[l][k - 1][1]) && (k == r || f[k + 1][r][0])) {
				if(vis[l - 1][k]) f[l][r][0] = 1;
				if(vis[k][r + 1]) f[l][r][1] = 1;
				if(l == 1 && r == n) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}
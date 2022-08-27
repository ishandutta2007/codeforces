#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, p[N], g[N];
char a[N], b[N];
bool check(int x) {
	L(i, 1, n) g[i] = 1;
	L(i, 1, x) g[p[i]] = 0;
	int now = 0;
	L(i, 1, n) {
		if(now < m && b[now + 1] == a[i] && g[i]) {
			++now;
		}
	}
	return now == m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> (a + 1) >> (b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	L(i, 1, n) cin >> p[i];
	int l = 0, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
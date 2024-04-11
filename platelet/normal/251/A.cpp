
 #include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
 
using namespace std;
const int N = 1e5 + 5;
int n, d, a[N];
int main() {
	cin >> n >> d;
	rep(i, 1, n) scanf("%d", &a[i]);
	long long ans = 0;
	rep(i, 1, n) {
		int cnt = upper_bound(a + 1, a + n + 1, a[i] + d) - a - i - 1;
		ans += cnt * (cnt - 1LL) / 2;
	}
	cout << ans;
	return 0;
}
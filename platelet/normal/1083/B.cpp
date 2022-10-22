#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 5e5 + 5;
int n, k; char a[N], b[N]; long long cnt, su, ans;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	scanf("%d%d%s%s", &n, &k, a, b);
	if(k == 1) return !printf("%d\n", n);
	int i = 0; while(i < n && a[i] == b[i]) i++;
	ans = n * 2 - i, k -= 2;
	for(i++; i < n && k; i++, cnt *= 2) {
		if(a[i] == 'a') cnt++; if(b[i] == 'b') cnt++;
		int res = min(cnt - su, 0LL + k); ans += 1LL * res * (n - i), k -= res, su += res;
	}
	cout << ans;
	return 0;
}
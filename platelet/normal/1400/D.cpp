#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
int main() {
	int t, n; static int a[3005], cnt[3005];
	for(cin >> t; t--;) {
		mem(cnt, 0);
		cin >> n; long long ans = 0;
		rep(i, 1, n) scanf("%d", &a[i]);
		per(i, n, 1) {
			long long sum = 0;
			per(j, i - 1, 1) {
				if(a[j] == a[i]) ans += sum;
				sum += cnt[a[j]];
			}
			cnt[a[i]]++;
		}
		cout << ans << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, cnt[N], a[N], ans[N], bh[N], tot;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], a[i] = n - a[i], cnt[a[i]] ++;
	L(i, 1, n) if(cnt[i] % i) return cout << "Impossible\n", 0;
	L(i, 1, n) {
		if(cnt[a[i]] % a[i] == 0) bh[a[i]] = ++tot;
		ans[i] = bh[a[i]], cnt[a[i]] --;
	}
	cout << "Possible\n";
	L(i, 1, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
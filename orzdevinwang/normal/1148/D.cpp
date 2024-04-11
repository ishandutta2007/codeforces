#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], b[N], ans[N], tot;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i] >> b[i];
	int cnta = 0, cntb = 0;
	L(i, 1, n) cnta += (b[i] > a[i]), cntb += (a[i] > b[i]);
	if(cnta > cntb) {
		L(i, 1, n) if(b[i] > a[i]) ans[++tot] = i;
		sort(ans + 1, ans + tot + 1, [&](int x, int y) { return a[x] > a[y]; });
		cout << tot << endl;
		L(i, 1, tot) cout << ans[i] << " ";
	}
	else {
		L(i, 1, n) if(a[i] > b[i]) ans[++tot] = i;
		sort(ans + 1, ans + tot + 1, [&](int x, int y) { return a[x] < a[y]; });
		cout << tot << endl;
		L(i, 1, tot) cout << ans[i] << " ";
	}
	return 0;
}
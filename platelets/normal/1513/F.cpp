#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;

int n, a[N], b[N];

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	vector <int> v1, v2;
	rep(i, 1, n) if(a[i] > b[i]) v1.pb(i); else v2.pb(i);
	sort(v1.begin(), v1.end(), [](int x, int y) { return b[x] < b[y]; });
	sort(v2.begin(), v2.end(), [](int x, int y) { return a[x] < a[y]; });
	int j = 0, as = 0, ma = 0;
	for(int i : v1) {
		while(j < v2.size() && a[v2[j]] <= b[i]) ma = max(ma, b[v2[j++]]);
		as = max(as, min(ma, a[i]) - b[i]);
	}
	j = ma = 0;
	for(int i : v2) {
		while(j < v1.size() && b[v1[j]] <= a[i]) ma = max(ma, a[v1[j++]]);
		as = max(as, min(ma, b[i]) - a[i]);
	}
	long long re = 0;
	rep(i, 1, n) re += abs(a[i] - b[i]);
	cout << re - as * 2;
	return 0;
}
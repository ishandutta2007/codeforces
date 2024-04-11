#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, m, a[N], cnt[N], fg[N];
ll ans, now;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i];
	R(i, n, 1) {
		if(!cnt[a[i]]) fg[i] = 1;
		cnt[a[i]] = 1;
	}
	L(i, 1, 1e5) cnt[i] = 0;
	L(i, 1, n) {
		if(fg[i]) ans += now; 
		now -= cnt[a[i]];
		cnt[a[i]] = 1;
		now += cnt[a[i]];
	}
	cout << ans << "\n";
	return 0;
}
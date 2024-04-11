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
const int N = 1e6 + 7;
int n, m, p[N], dep[N], cnt[N], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, cnt[0] ++;
	L(i, 2, n) cin >> p[i], dep[i] = dep[p[i]] + 1, cnt[dep[i]] ++;
	L(i, 0, n) ans += (cnt[i] & 1);
	cout << ans << "\n";
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
ll s[N], e[N], E, o[N];
int n;
int mex(int x, int y) { return ((x && y) ? 0 : ((x == 2 || y == 2) ? 1 : 2)); }
int calc(int x) {
	R(i, n, 1) {
		int o0 = (!x), o1 = (!x), c0, c1;
		for(ll r = e[i], l; r; r = l - 1) {
			l = r / 2 + 1;
			if(r % 2 == 0) c0 = mex(o1, o0), c1 = mex(c0, o0);
			else c1 = mex(o0, o0), c0 = mex(c1, o0);
			o0 = c0, o1 = c1;
			if(l <= s[i] && s[i] <= r) {
				x = (s[i] % 2 == 0 ? c0 : c1);
				break;
			}
		}
	}
	return (!!x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> s[i] >> e[i];
	cout << calc(0) <<  " " << calc(1) << "\n";
	return 0;
}
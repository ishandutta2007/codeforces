#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 6e5 + 7;
int a, b, n, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a >> b, n = a + b;
	for(int l = 1, r, s; l <= n; l = r + 1) {
		s = n / l, r = n / s;
		int al = (a + s) / (s + 1), ar = a / s, bl = (b + s) / (s + 1), br = b / s;
		if(al <= ar && bl <= br) ans += min(ar + br, r) - max(al + bl, l) + 1;
	}
	cout << ans << endl;
	return 0;
}
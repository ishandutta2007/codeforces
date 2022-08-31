#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int W, n;
int a[N];
int cnt[33];
void Main() {
	cin >> n >> W;
	L(i, 1, n) cin >> a[i], cnt[__builtin_ctz(a[i])] ++;
	int ns = 0;
	while(n) {
		int now = W;
		R(i, 30, 0) if(now >= (1 << i)) {
			int g = min(now >> i, cnt[i]);
			cnt[i] -= g, n -= g, now -= (g << i);
		}
		ns ++;
	}
	L(i, 0, 30) cnt[i] = 0;
	cout << ns << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}
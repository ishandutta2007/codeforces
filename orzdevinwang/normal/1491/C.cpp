#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, S[N], f[N], cnt, u, v;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void work(int x) {
	while(1) {
		int To = x + S[x];
		S[x] --;
		if(S[x] == 1) f[x] = find(x + 1);
		if(To > n) return;
		x = find(To);
		if(x > n) return;
	}
}
void Main() {
	ll ans = 0;
	cin >> n;
	L(i, 1, n) cin >> S[i];
	L(i, 1, n + 1) f[i] = i;
	L(i, 1, n) if(S[i] == 1) f[i] = find(i + 1);
	L(i, 1, n) if(S[i] != 1) {
		if(S[i] > n) ans += S[i] - n, S[i] = n;
		while(S[i] > 1) 
			ans ++, work(i);
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}
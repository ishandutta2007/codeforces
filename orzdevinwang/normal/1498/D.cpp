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
const int N = 2e5 + 7;
int m, n;
int f[N];
ll mul(int x, ll y) {
	return (y * x + 99999) / 100000;
}
void Main() {
	cin >> n >> m;
	memset(f, -1, sizeof(f));
	f[0] = 0;
	L(T, 1, n) {
		int op, y; cin >> op;
		ll x; cin >> x >> y;
		if(op == 1) {
			x = (x + 99999) / 100000; 
			R(i, m, 0) if(f[i] != -1) {
				int now = i, c = y;
				while(now + x <= m && f[now + x] == -1 && c) 
					now += x, f[now] = T, -- c;
			}
		}
		else {
			R(i, m, 0) if(f[i] != -1) {
				int now = i, c = y;
				while(mul(now, x) <= m && f[mul(now, x)] == -1 && c) 
					now = mul(now, x), f[now] = T, -- c;
			}
		}
	}
	L(i, 1, m) cout << f[i] << " ";
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}
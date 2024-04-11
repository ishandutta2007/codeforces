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
int u, v, s[N], t[N], stop, ttop;
void Main() {
	cin >> u >> v;
	if(u > v) return cout << "NO\n", void();
	stop = ttop = 0;
	L(i, 0, 29) if(u >> i & 1) s[++stop] = i;
	L(i, 0, 29) if(v >> i & 1) t[++ttop] = i;
	if(stop < ttop) return cout << "NO\n", void();
	L(i, 1, ttop) if(t[i] < s[i]) return cout << "NO\n", void();
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}
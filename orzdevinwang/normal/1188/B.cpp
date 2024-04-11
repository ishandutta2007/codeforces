#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
int n, p, k, a[N];
map <int, int> mp;
ll ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> p >> k;
	L(i, 1, n) {
		int s, w;
		cin >> s, w = ((ll) s * s % p * s % p * s % p + p - (ll) s * k % p) % p;
		ans += mp[w], mp[w] ++;
	}
	cout << ans << "\n";
	return 0;
}
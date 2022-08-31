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
const int N = 1e6 + 7;
int n, tot, cnt[N];
ll a[N], s[N], ns = 1;
mt19937_64 orz(time(0) ^ clock());
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	int T = 10;
	while(T--) {
		int c = orz() % n + 1;
		tot = 0;
		L(i, 1, sqrt(a[c])) if(a[c] % i == 0) {
			s[++tot] = a[c] / i;
			if(i != a[c] / i) s[++tot] = i;
		}
		sort(s + 1, s + tot + 1);
		L(i, 1, tot) cnt[i] = 0;
		L(i, 1, n) ++ cnt[lower_bound(s + 1, s + tot + 1, __gcd(a[i], a[c])) - s];
		L(i, 1, tot) L(j, i + 1, tot) if(s[j] % s[i] == 0) cnt[i] += cnt[j];
		L(i, 1, tot) if(cnt[i] * 2 >= n) ns = max(ns, s[i]);
//		cout << c << " : " << ns << "\n";
	}
	cout << ns << "\n";
	return 0;
}
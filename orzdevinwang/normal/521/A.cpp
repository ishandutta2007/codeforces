#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
void Min(int &x, int y) { if(x > y) x = y; }
void Max(int &x, int y) { if(x < y) x = y; }
const int N = 1e6 + 7; 
const int mod = 1e9 + 7;
int n, m, cnt[N];
char s[N];
int get(char ch) {
	return (ch > 'A') + (ch > 'C') + (ch > 'G') + (ch > 'T');
}
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> s + 1;
	L(i, 1, n) {
		cnt[get(s[i])] ++;
	}
	int maxn = 0, pp = 0;
	L(i, 0, 3) maxn = max(maxn, cnt[i]);
	L(i, 0, 3) if(cnt[i] == maxn) pp ++;
	cout << qpow(pp, n) << endl;
	return 0;
}
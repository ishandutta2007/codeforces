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
int n, ans, g[N][26];
char s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s, n = strlen(s);
	L(ch, 0, 25) {
		L(i, 0, n - 1) if(s[i] - 'a' == ch) L(j, 0, n - 1) g[j][s[(i + j) % n] - 'a'] ++;
		int mx = 0;
		L(i, 0, n - 1) {
			int sum = 0;
			L(ch, 0, 25) if(g[i][ch] == 1) sum ++;
			L(ch, 0, 25) g[i][ch] = 0;
			mx = max(mx, sum);	
		}
		ans += mx;
	}
	cout.precision(12), cout << fixed;
	cout << 1. * ans / n << "\n";
	return 0;
}
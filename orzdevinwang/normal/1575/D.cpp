#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int n, ns, w[N], lst[N];
char s[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (s + 1), n = strlen(s + 1);
	if(n == 1) {
		if('1' <= s[1] && s[1] <= '9') cout << 0 << '\n';
		else cout << 1 << '\n';
		return 0;
	}
	int ns = 0;
	L(X, 0, 9) {
		int cnt = 0;
		L(i, 1, n) w[i] = -1;
		L(i, 1, n) {
			if(s[i] == 'X') cnt += 1, w[i] = X;
			else if('0' <= s[i] && s[i] <= '9') w[i] = s[i] - '0';
		}
		if(!cnt && X) continue;
		int r1 = w[n - 1], r2 = w[n];
		for (int a = 0; a <= 75; a += 25) {
			w[n - 1] = r1, w[n] = r2;
			if(w[n - 1] != -1 && w[n - 1] != a / 10) continue;
			if(w[n] != -1 && w[n] != a % 10) continue;
			w[n - 1] = a / 10, w[n] = a % 10;
			if(w[1] == 0) continue;
			int ret = 1;
			if(w[1] == -1) ret *= 9;
			L(i, 2, n) if(w[i] == -1) ret *= 10;
			ns += ret;
		}
	}
	cout << ns << '\n';
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = (1 << 18) + 5;

int K, q, c[N * 2];
char s[N];
void upd(int p) {
	for(; p; p /= 2) {
		c[p] = 0;
		if(s[p] != 48) c[p] += c[p * 2];
		if(s[p] != 49) c[p] += c[p * 2 + 1];
		// cout << p << ' ' << c[p] << endl;
	}
}

int main() {
	scanf("%d%s", &K, s + 1);
	reverse(s + 1, s + (1 << K));
	For(i, 1 << K, 1 << K + 1) c[i] = 1;
	For(i, 1, 1 << K) upd(i);
	int p; char ch[2];
	for(cin >> q; q--;) {
		scanf("%d%s", &p, ch), p = (1 << K) - p;
		s[p] = ch[0], upd(p);
		printf("%d\n", c[1]);
	}
	return 0;
}
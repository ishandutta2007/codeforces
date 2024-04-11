#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2005;
typedef long long ll;

int n, vs[N]; char s[N];
struct poi {
	int x, y;
	poi operator -(const poi& b) {
		return {x - b.x, y - b.y};
	}
	ll operator *(const poi& b) {
		return (ll)y * b.x - (ll)x * b.y;
	}
} a[N];

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	int nw = 0, mi = 2e9;
	rep(i, 1, n) {
		scanf("%d%d", &a[i].x, &a[i].y);
		if(a[i].x < mi) nw = i, mi = a[i].x;
	} 
	scanf("%s", s + 2);
	vs[nw] = 1, cout << nw;
	rep(i, 2, n) {
		auto chk = [&](ll x) {
			return s[i] == 'R' ? x > 0 : x < 0;
		};
		int nxt = 0;
		rep(i, 1, n) if(!vs[i] && (!nxt || chk((a[i] - a[nw]) * (a[nxt] - a[nw])))) nxt = i;
		vs[nw = nxt] = 1, printf(" %d", nw);
	}
	return 0;
}
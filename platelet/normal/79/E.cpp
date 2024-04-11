#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

int n, a, b, c, x = 1, y = 1;
ll A, B, C, D;

ll calc(int x, int y, int X, int Y, int ox, int oy) {
    ll d = X + Y - x - y;
    return (abs(x + (X > x) - ox) + abs(y + (Y > y) - oy) + abs(X - ox) + abs(Y - oy)) * d >> 1;
}
bool chk(int x, int y, ll A, ll B, ll C, ll D, bool t) {
	if(x == 5 && y == 8) {
		int fuck = 1;
	}
    if(max(x, y) > n) return 0;
    if(t) {
        A -= abs(x - a) + abs(y - b);
        B -= abs(x - a - c) + abs(y - b);
        C -= abs(x - a) + abs(y - b - c);
        D -= abs(x - a - c) + abs(y - b - c);
    }
    auto go = [&](int X, int Y, bool t) {
        A -= calc(x, y, X, Y, a, b), D -= calc(x, y, X, Y, a + c, b + c);
        if(t) B -= calc(x, y, X, Y, a + c, b), C -= calc(x, y, X, Y, a, b + c);
        x = X, y = Y;
    };
    if(x < a) go(a, y, 1);
    if(y < b) go(x, b, 1);
    if(x < a + c && y < b + c) {
        ll B1 = B - calc(x, y, a + c, y, a + c, b) - calc(a + c, y, a + c, b + c, a + c, b);
        ll C1 = C - calc(x, y, a + c, y, a, b + c) - calc(a + c, y, a + c, b + c, a, b + c);
        ll B2 = B - calc(x, y, x, b + c, a + c, b) - calc(x, b + c, a + c, b + c, a + c, b);
        ll C2 = C - calc(x, y, x, b + c, a, b + c) - calc(x, b + c, a + c, b + c, a, b + c);
        if((B1 < C1) ^ (B2 < C2)) B = C = B1 + C1 >> 1;
        else if(min(B1, C1) > min(B2, C2)) B = B1, C = C1;
        else B = B2, C = C2;
        go(x, b + c, 0), go(a + c, b + c, 0);
    }
    if(x < a + c) go(a + c, y, 1);
    if(y < b + c) go(x, b + c, 1);
    go(n, y, 1), go(x, n, 1);
    return min({A, B, C, D}) >= 0;
}
int main() {
    cin >> n >> A >> a >> b >> c, c--;
    D = C = B = A;
    if(!chk(1, 1, A, B, C, D, 0)) puts("Impossible"), exit(0);
    while(min(x, y) < n) {
        if(chk(x + 1, y, A, B, C, D, 1)) putchar('R'), x++;
        else putchar('U'), y++;
        A -= abs(x - a) + abs(y - b);
        B -= abs(x - a - c) + abs(y - b);
        C -= abs(x - a) + abs(y - b - c);
        D -= abs(x - a - c) + abs(y - b - c);
    }
}
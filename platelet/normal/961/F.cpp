#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 1e6 + 5;

int n, ans[N];
char s[N];

void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    if(x < 0) pc(45), x = -x;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(32);
}

template<int base, int mod> struct Hash {
    int pow[N], v[N];
    void init() {
        rep(i, 0, n) pow[i] = i ? (ll)pow[i - 1] * base % mod : 1;
        rep(i, 1, n) v[i] = ((ll)v[i - 1] * base + s[i]) % mod;
    }
    inline bool operator ()(int s1, int s2, int l) {
        return (v[s1 + l] - v[s2 + l] + pow[l] * ll(v[s2] - v[s1])) % mod == 0;
    }
};
Hash<131, 1000000007> A;
Hash<31, 1000000009> B;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    scanf("%d%s", &n, s + 1);
    A.init(), B.init();
    int len = -1;
    per(i, n + 1 >> 1, 1) {
        if(len + 2 < n - i * 2 + 2) len += 2;
        while(~len && (!A(i - 1, n - i + 1 - len, len) || !B(i - 1, n - i + 1 - len, len))) len -= 2;
        ans[i] = len;
    }
    rep(i, 1, n + 1 >> 1) wrt(ans[i]);
}
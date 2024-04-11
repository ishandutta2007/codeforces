#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define _(...) __VA_ARGS__
#define _asm(arg, ...) a##sm __volatile__(#__VA_ARGS__:arg)

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, a[N];
ll f[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    mem(f, 192), f[0] = 0;
    rep(i, 1, n) {
        _asm(_(:"S"(f + i), "D"(f), "a"((ll)a[i] * i), "d"((ll)a[i]):"%rbx", "%rcx"),
            L1:
                mov %%rax, %%rbx;
                add -8(%%rsi), %%rbx;
                mov (%%rsi), %%rcx;
                cmp %%rcx, %%rbx;
                cmovg %%rbx, %%rcx;
                mov %%rcx, (%%rsi);
                sub %%rdx, %%rax;
                sub $8, %%rsi;
                cmp %%rsi, %%rdi;
            jb L1;
        );
        if(i == N - 1) rep(i, 0, n) cout << f[i] << endl;
    }
    ll ans = 0;
    rep(i, 1, n) ans = max(ans, f[i]);
    cout << ans;
}
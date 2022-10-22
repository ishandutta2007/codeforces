#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

template<class T> T& cmin(T& a, const T& b) { if(b < a) a = b; return a; }
template<class T> T& cmax(T& a, const T& b) { if(a < b) a = b; return a; }

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;

const int N = 1e5 + 5;

int n, fa[N << 1], stk[N];
char s[N << 1];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
    cin >> n >> s;
    rep(i, 1, n << 1) fa[i] = i;
    int p = 0;
    rep(i, 1, n << 1) if(s[i - 1] == '(') stk[++p] = i;
    else {
        int x = stk[p--];
        fa[find(i)] = find(x);
        if(x > 1 && s[x - 2] == ')') fa[find(i)] = find(x - 1);
    }
    int cnt = 0;
    rep(i, 1, n << 1) cnt += fa[i] == i;
    cout << cnt << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) solve();
}
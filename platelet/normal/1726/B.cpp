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

int n, m;

void solve() {
    cin >> n >> m;
    if(m < n) { cout << "No\n"; return; }
    if(n % 2 == 0) {
        if(m & 1) { cout << "No\n"; return; }
        cout << "Yes\n";
        rep(i, 1, n / 2 - 1) cout << "1 1 ";
        int v = m / 2 - (n / 2 - 1);
        cout << v << ' ' << v << '\n';
    } else {
        cout << "Yes\n";
        rep(i, 1, n - 1) cout << "1 ";
        cout << m - (n - 1) << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) solve();
}
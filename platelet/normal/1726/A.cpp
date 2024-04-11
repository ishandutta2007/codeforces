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

const int N = 2005;

int n, a[N];

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    if(n == 1) { cout << "0\n"; return; }
    int ans = max(*max_element(a + 2, a + n + 1) - a[1], a[n] - *min_element(a + 1, a + n));
    rep(i, 1, n) cmax(ans, a[n] - a[1]), rotate(a + 1, a + 2, a + n + 1);
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) solve();
}
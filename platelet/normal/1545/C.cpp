#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 505;

int n, a[N * 2][N], vs[N * 2], ct[N];

int main() {
    int T;
    for(cin >> T; T--;) {
        cin >> n, mem(vs, 0);
        rep(i, 1, n * 2) rep(j, 1, n) scanf("%d", &a[i][j]);
        vector<int> b;
        int as = 1;
        auto del = [&](int i) {
            vs[i] = 1, b.pb(i);
            rep(j, 1, n * 2) if(!vs[j]) rep(k, 1, n) if(a[i][k] == a[j][k]) { vs[j] = 1; break; }
        };
        auto solve = [&]() {
            rep(k, 1, n) {
                mem(ct, 0);
                rep(i, 1, n * 2) if(!vs[i]) ct[a[i][k]]++;
                rep(i, 1, n) if(ct[i] == 1) rep(j, 1, n * 2) if(!vs[j] && a[j][k] == i) return del(j);
            }
            rep(i, 1, n * 2) if(!vs[i]) return as = as * 2 % 998244353, del(i);
        };
        while(b.size() < n) solve();
        printf("%d\n", as);
        for(int i : b) printf("%d ", i);
    }
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ull = uint64_t;

const int N = 1e6 + 5;

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

int n; ull a[N];
bool vis[N];

void print(vector<int> v) {
    cout << n - v.size() << '\n';
    mem(vis, 0);
    for(int i : v) vis[i] = 1;
    rep(i, 1, n) if(!vis[i]) printf("%d ", i);
    exit(0);
}
int main() {
    cin >> n;
    rep(i, 2, n) if(!vis[i]) {
        ull x = Rand();
        for(long long t = i; t <= n; t *= i)
            for(int k = t; k <= n; k += t) vis[k] = 1, a[k] ^= x;
    }
    ull all = 0;
    rep(i, 1, n) all ^= a[i] ^= a[i - 1];
    if(all == 0) print({});
    rep(i, 1, n) if(a[i] == all) print({i});
    unordered_map<ull, int> p;
    rep(i, 1, n) {
        if(p.count(all ^ a[i])) print({i, p[all ^ a[i]]});
        p[a[i]] = i;
    }
    print({2, n / 2, n});
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const int N = 3e5 + 5;

int n, m, K, a[N], q[N];
ll as[N];
vector<pair<int, int>> v[N];
vector<tuple<int, int, ll>> s[N];

void ins(auto& s, int x, int v) {
    while(s.size() && get<1>(s.back()) >= v) s.pop_back();
    if(s.size()) s.eb(x, v, v * ll(x - get<0>(s.back())) + get<2>(s.back()));
    else s.eb(x, v, (ll)v * x);
}
int main() {
    cin >> n >> m >> K;
    rep(i, 1, n) scanf("%d", &a[i]);
    int l, r;
    rep(i, 1, m) scanf("%d%d", &l, &r), v[l].eb(r, i);
    l = 1, r = 0;
    per(i, n, 1) {
        while(l <= r && a[i] <= a[q[r]]) r--;
        q[++r] = i;
        if(q[l] == i + K) l++;
        ins(s[i % K], (n - i) / K + 1, a[q[l]]);
        ins(s[(i + 1) % K], (n - i + K - 1) / K + 1, a[i]);
        for(auto [r, id] : v[i]) {
            int R = (n - i + K - 1) / K + 1 - (r - i + K) / K;
            auto [x, v, su] = *lower_bound(all(s[(i + 1) % K]), tuple(R, 0, 0LL));
            as[id] = get<2>(s[(i + 1) % K].back()) - su + ll(x - R) * v;
        }
    }
    rep(i, 1, m) printf("%lld\n", as[i]);
}
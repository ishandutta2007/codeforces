#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, k; char s[N];
ll d[N];
vector<pair<int, int>> G[N];
struct node {
    int u; ll d;
    bool operator<(const node& b)const {
        return d > b.d;
    }    
};
int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%s", &n, &k, s + 1);
    rep(i, 1, n) {
        if(s[i] == 49) G[max(0, i - k - 1)].eb(min(n, i + k), i);
        G[i].eb(i - 1, 0), G[i - 1].eb(i, i);
    }
    priority_queue<node> q;
    q.push({0, 0}), mem(d, 63), d[0] = 0;
    while(q.size()) {
        auto [u, dis] = q.top(); q.pop();
        if(dis > d[u]) continue;
        for(auto [v, w] : G[u]) if(dis + w < d[v])
            d[v] = dis + w, q.push({v, d[v]});
    }
    cout << d[n];
}
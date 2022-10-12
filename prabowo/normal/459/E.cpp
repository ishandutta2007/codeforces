#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;

int n, m;
int dp[300002];
vector <pii> later;

struct Edge {
    int from, to, w;
} edge[300002];

bool cmp(Edge u, Edge v) {
    return u.w < v.w;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].w);

    sort(edge, edge+m, cmp);

    int now = edge[0].w;
    for (int i=0; i<m; i++) {
        if (now < edge[i].w) {
            now = edge[i].w;
            while (later.size()) {
                dp[later.back().fi] = max(dp[later.back().fi], later.back().se);
                later.pop_back();
            }
        }

        later.pb(mp(edge[i].to, 1 + dp[edge[i].from]));
    }

    while (later.size()) {
        dp[later.back().fi] = max(dp[later.back().fi], later.back().se);
        later.pop_back();
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, dp[i+1]);
    }

    printf("%d\n", ans);
    return 0;
}
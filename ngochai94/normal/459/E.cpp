#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

int n, m, u, v, w, ans[300005];
pair<int, pair<int, int> > edge[300005];
vector<pair<int, int> > update;

int main(){
    ios::sync_with_stdio(0);
    scanf("%d %d", &n, &m);
    REP (i, m) {
        scanf("%d %d %d", &u, &v, &w);
        edge[i] = {w, {u, v}};
    }
    sort(edge, edge + m);
    int bef = 0;
    REP (i, m) {
        w = edge[i].first;
        u = edge[i].second.first;
        v = edge[i].second.second;
        if (w > bef) {
            bef = w;
            for (auto p: update) {
                ans[p.first] = max(ans[p.first], p.second);
            }
            update.clear();
        }
        update.pb({v, ans[u] + 1});
    }
    for (auto p: update) ans[p.first] = max(ans[p.first], p.second);
    int res = 0;
    FOR (i, 1, n) res = max(res, ans[i]);
    printf("%d", res);
}
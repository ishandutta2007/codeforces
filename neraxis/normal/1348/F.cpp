#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int ll[N], rr[N], pos[N];
vector<pair<ii, int>> ve;
int n;
int ans[N];
int it[4 * N];

void build(int k, int l, int r) {
    if (l == r) {
        it[k] = rr[pos[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

int dfs(int k, int l, int r, int u, int v, int val) {
    // cout << k << ' ' << l << ' ' << r << ' ' << u << ' ' << v << ' ' << val << endl;
    if (u > v) return 0;
    if (l > v || r < u) return 0;
    int mid = (l + r) / 2;
    if (l == r) {
        if (it[k] >= val) return l;
        else return 0;
    }
    if (l >= u && r <= v && it[k] < val) return 0;
    else if (l >= u && r <= v) {
        if (it[2 * k] >= val) return dfs(2 * k, l, mid, u, v, val);
        else return dfs(2 * k + 1, mid + 1, r, u, v, val);
    } 
    int g1 = dfs(2 * k, l, mid, u, v, val);
    int g2 = dfs(2 * k + 1, mid + 1, r , u, v, val);
    return max(g1, g2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ll[i] >> rr[i];
        ve.push_back({{ll[i], rr[i]}, i});
    }
    sort(all(ve));
    int cur = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++) {
        while (cur < n && ve[cur].x.x <= i) {
            // cout << "fuck " << i << ' ' << ve[cur].y << endl;
            pq.push({ve[cur].x.y, ve[cur].y});
            cur++;
        }
        ii u = pq.top();
        pq.pop();
        pos[i] = u.y;
        // cout << "debug " << i << ' ' << u.y << endl;
    }
    for (int i = 1; i <= n; i++) {
        ans[pos[i]] = i;
    }
    build(1, 1, n);
    ii to_swap = {0, 0};
    for (int i = 2; i <= n; i++) {
        int foo = dfs(1, 1, n, ll[pos[i]], i - 1, i);
        // if (i == 3) cout << foo << endl;
        if (foo != 0) {
            to_swap = {foo, i};
            break;
        }
    }   
    // for (int i = 1; i <= 7; i++) cout << it[i] << ' ';
    // cout << endl;
    // cout << dfs(1, 1, n, 2, 2, 3) << endl;
    if (to_swap == ii(0, 0)) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    } else {
        cout << "NO\n";
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
        swap(pos[to_swap.x], pos[to_swap.y]);
        for (int i = 1; i <= n; i++) ans[pos[i]] = i;
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    }
    return 0;
}
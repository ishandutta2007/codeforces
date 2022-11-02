#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double

const int inf = 1e15;
const int N = 2e5 + 3;

int n, m;
vector<pii> gr[N];
int dist[N];
bool used[N];

void min_ostov(int st) {
    auto comp = [dist](int v1, int v2) {
        if (dist[v1] != dist[v2]) return dist[v1] > dist[v2];
        return v1 < v2;
    };

    set<int, decltype(comp)> b(comp);   

    dist[st] = 0;
    b.emplace(st);

    while(sz(b)) {
        int v = (*b.begin());
        used[v] = true;
        b.erase(b.begin());

        for(auto to : gr[v]) {
            if (!used[to.fi] && dist[to.fi] < to.se) {
                b.erase(to.fi);
                dist[to.fi] = to.se;
                b.emplace(to.fi);
            }
        }
    }
}

void solve() {
    cin >> m >> n;
    vector<int> a(m), b(n);

    fill(dist, dist + N, -inf);
    for(int i = 0;i < m;i++) 
        cin >> a[i];
    for(int i = 0;i < n;i++)
        cin >> b[i];

    int res = 0;

    for(int i = 0;i < m;i++) {
        int c;
        cin >> c;
        while(c--) {
            int to;
            cin >> to;
            to--;
            gr[i].emplace_back(to + m, a[i] + b[to]);
            gr[to + m].emplace_back(i, a[i] + b[to]);
            res += a[i] + b[to];
        }
    }

    //cout << res << endl;

    for(int i = 0;i < n + m;i++) {
        if (!used[i]) {
            min_ostov(i);
        }
        res -= dist[i];
    }

    cout << res << endl;
}

 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}
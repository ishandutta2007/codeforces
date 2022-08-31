#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 4e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> dist(n + 1, INFi);
    vector<int> p(n + 1);
    vector<int> pk(n + 1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x = 0; x <= min(v, k); ++x) {
            int d = k - x;
            if (v + d > n) continue;
            int be = v - x + d;
            if (dist[be] == INFi) {
                dist[be] = dist[v] + 1;
                p[be] = v;
                pk[be] = x;
                q.push(be);
            }
        }
    }
    if (dist[n] == INFi) {
        cout << "-1\n";
        return;
    }
    vector<int> path;
    int v = n;
    while(v != 0) {
        path.push_back(pk[v]);
        v = p[v];
    }
    reverse(all(path));
    vector<bool> have(n);
    int ans = 0;
    for(auto t : path) {
        int t2 = k - t;
        vector<int> vec;
        range(i, n) {
            if (have[i]) {
                if (t) {
                    vec.push_back(i);
                    have[i] = false;
                    t--;
                }
            } else {
                if (t2) {
                    vec.push_back(i);
                    have[i] = true;
                    t2--;
                }
            }
        }
        cout << "? ";
        for(auto &v : vec) cout << v + 1 << ' ';
        cout << endl;
        int x; cin >> x;
        ans ^= x;
    }
    cout << "! " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
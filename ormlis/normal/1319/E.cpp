//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < n; ++i)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()


using namespace std;

typedef long long ll;
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5+1;
const int md = 998244353;

ll tree[maxN*8+1], arr[maxN*2];
ll upde[maxN*8+1];

void push(int v) {
    tree[v * 2] += upde[v];
    tree[v * 2 + 1] += upde[v];
    upde[v * 2] += upde[v];
    upde[v * 2 + 1] += upde[v];
    upde[v] = 0;
}

void make(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = arr[l];
        upde[v] = 0;
    } else {
        make(v * 2, l, (l + r) / 2);
        make(v * 2 + 1, (l + r) / 2, r);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}

void upd(int v, int l, int r, int lq, int rq, ll x) {
    if (r <= lq || l >= rq) return;
    if (lq <= l && r <= rq) {
        tree[v] += x;
        upde[v] += x;
        return;
    }
    push(v);
    upd(v * 2, l, (l + r) / 2, lq, rq, x);
    upd(v * 2 + 1, (l + r) / 2, r, lq, rq, x);
    push(v);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

ll get() {
    return tree[1];
}

void solve() {
    range(i, maxN*8+1) tree[i] = -INF;
    range(i, maxN*2) arr[i] = -INF;
    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<int, int>> a(n), b(m);
    range(i, n) cin >> a[i].first >> a[i].second;
    range(i, m) cin >> b[i].first >> b[i].second;
    sort(all(a));
    sort(all(b));
    vector<pair<int, int>> aw, bw;
    range(i, n) {
        while (!aw.empty() && a[i].second <= aw.back().second) {
            aw.pop_back();
        }
        aw.push_back(a[i]);
    }
    range(i, m) {
        while(!bw.empty() && b[i].second <= bw.back().second) {
            bw.pop_back();
        }
        bw.push_back(b[i]);
    }
    a = aw;
    b = bw;
    n = a.size();
    m = b.size();

    range(i, m) {
        arr[i] = -b[i].second;
    }
    make(1, 0, m);

    vector<pair<pair<int, int>, int>> ms(p);
    range(i, p) {
        cin >> ms[i].first.first >> ms[i].first.second >> ms[i].second;
    }
    sort(all(ms));
    ll ans = -INF;
    int j = 0;
    range(i, n) {
        while(j < p && ms[j].first.first < a[i].first) {
            pair<int, int> ke = {ms[j].first.second, INFi};
            int e = upper_bound(all(b), ke) - b.begin();
            if (e != m) {
                upd(1, 0, m, e, m, ms[j].second);
            }
            j++;
        }
        ans = max(ans, get() - a[i].second);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //auto sad = mt19937(2231337);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
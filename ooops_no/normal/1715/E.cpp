#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 1e5 + 10;
const ll INF = 1e18;
vector<pair<int,int>> g[N];
int n, m, k;

void upd_edge(vector<ll> &d) {
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++) {
        st.insert({d[i], i});
    }
    while (st.size() > 0) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto to : g[v]) {
            if (d[to.first] > d[v] + to.second) {
                st.erase({d[to.first], to.first});
                d[to.first] = d[v] + to.second;
                st.insert({d[to.first], to.first});
            }
        }
    }
}

struct line {
    ld k, b;
};

deque<line> q;

ld cross(line a, line b) {
    return (b.b - a.b) / (a.k - b.k);
}

void add1(line a) {
    while (q.size() >= 2 && cross(q[(int)(q.size()) - 2], a) < cross(q[(int)(q.size()) - 2], q.back())) {
        q.pop_back();
    }
    q.pb(a);
}

line get1(int x) {
    int l = 0, r = q.size();
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (cross(q[mid - 1], q[mid]) <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return q[l];
}

void add2(line a) {
    while (q.size() >= 2 && cross(q[(int)(q.size()) - 2], a) > cross(q[(int)(q.size()) - 2], q.back())) {
        q.pop_back();
    }
    q.pb(a);
}

line get2(int x) {
    int l = 0, r = q.size();
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (x <= cross(q[mid - 1], q[mid])) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return q[l];
}

ld pw(ll i) {
    return i * i;
}

void upd_fly(vector<ll> &d) {
    vector<ll> was_d(n);
    for (int i = 0; i < n; i++) {
        was_d[i] = d[i];
    }
    q.clear();
    for (int i = 0; i < n; i++) {
        if (q.size() > 0) {
            line l = get1(i + 1);
            d[i] = min(d[i], (ll)(l.k * (i + 1) + pw(i + 1) + l.b));
        }
        add1({-2 * (i + 1), pw(i + 1) + was_d[i]});
    }
    q.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (q.size() > 0) {
            line l = get2(i + 1);
            d[i] = min(d[i], (ll)(l.k * (i + 1) + pw(i + 1) + l.b));
        }
        add2({-2 * (i + 1), pw(i + 1) + was_d[i]});
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    vector<ll> d(n, INF);
    d[0] = 0;
    for (int i = 0; i < k; i++) {
        upd_edge(d);
        upd_fly(d);
    }
    upd_edge(d);
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
    }
    cout << endl;
    return 0;
}
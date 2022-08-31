#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

set<int> q1;
queue<int> q2;
int n; ll p;
ll cur_time = 0;

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    int get(int i) {
        ll res = 0;
        for (; ~i; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

fenwick f;
ll res[maxN];

void add_in_q2(int i) {
    q2.push(i);
}

void add_in_q1(int i) {
    q1.insert(i);
}

void check_q1() {
    if (q1.empty()) return;
    int i = *q1.begin();
    if (f.get(i - 1) == i) {
        q1.erase(i);
        f.upd(i, -1);
        add_in_q2(i);
    }
}

bool check_q2() {
    check_q1();
    if (q2.empty()) return false;
    int i = q2.front();
    cur_time += p;
    q2.pop();
    res[i] = cur_time;
    f.upd(i, 1);
    check_q1();
    return true;
}


void solve() {
    cin >> n >> p;
    f.build(n);
    range(i, n) f.upd(i, 1);
    vector<pair<ll, int>> t(n);
    range(i, n) {
        cin >> t[i].first;
        t[i].second = i;
    }
    sort(all(t));
    for (auto &w: t) {
        ll time = w.first;
        int ps = w.second;
        while (cur_time + p < time) {
            if (!check_q2()) {
                break;
            }
        }
        if (q1.empty() && q2.empty()) cur_time = time;
        add_in_q1(ps);
        check_q1();
    }
    while(check_q2()) {
    }
    range(i, n) cout << res[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
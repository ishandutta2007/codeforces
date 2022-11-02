#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

#define long long long

using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 1;

struct fenwick {
    vector<int> sum;

    fenwick(int n) {
        sum.clear();
        sum.resize(n, 0);
    }

    int f(int v) {
        return (v & (v + 1));
    }

    int h(int v) {
        return (v | (v + 1));
    }


    void add(int v) {
        while (v < sum.size()) {
            sum[v]++;
            v = h(v);
        }
    }

    int get(int r) {
        int ans = 0;
        while (r >= 0) {
            ans += sum[r];
            r = f(r) - 1;
        }
        return ans;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};


int n;
pair<int, int> a[max_n];
int sq[max_n];


void scan() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    sort(a, a + n);

    map<int, vector<int>> temp;
    for (int i = 0; i < n; i++) temp[a[i].second].emplace_back(i);
    int cnt = 0;
    for (auto i : temp) {
        for(int j : i.second) {
            sq[j] = cnt;
            cnt++;
        }
    }
}

void solve() {
    scan();

    long ans = 0;

    fenwick one = fenwick(n);
    for (int i = 0; i < n; i++) {
        ans += (long)one.get(sq[i]) * a[i].first;
        one.add(sq[i]);

    }


    fenwick two = fenwick(n);

    for (int i = n - 1; i >= 0; i--) {
        ans -= (long)two.get(sq[i], n - 1) * a[i].first;
        two.add(sq[i]);
    }

    cout << ans;
}


signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
}
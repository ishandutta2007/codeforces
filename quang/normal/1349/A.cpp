#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int p[N];
vector<int> a[N];

vector<pair<int, int>> getDivs(int u) {
    vector<pair<int, int>> res;
    while (u > 1) {
        int v = p[u];
        int cnt = 0;
        while (u % v == 0) {
            u /= v;
            cnt++;
        }
        res.push_back({v, cnt});
    }
    return res;
}

int pow(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res *= u;
        u *= u;
        v >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i; j < N; j += i) {
                if (!p[j]) p[j] = i;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        vector<pair<int, int>> divs = getDivs(u);
        for (auto val : divs) {
            a[val.first].push_back(val.second);
        }
    }

    long long res = 1;
    for (int i = 2; i < N; i++) {
        if (p[i] != i) continue;
        sort(a[i].begin(), a[i].end());
        if (a[i].size() == n) {
            res *= pow(i, a[i][1]);
        } else if (a[i].size() == n - 1) {
            res *= pow(i, a[i][0]);
        }
    }
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5e5 + 5;

int n, a[N];
ll pref[N], suf[N];
int les1[N], les2[N];

ll f(int x) {
    return pref[x] + suf[x] - a[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() and a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            les1[i] = s.top();
        } else les1[i] = -1;
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() and a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            les2[i] = s.top();
        } else les2[i] = -1;
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (les1[i] == -1) {
            pref[i] = (i + 1) * (ll)a[i];
        } else {
            pref[i] = (i - les1[i]) * (ll)a[i] + pref[les1[i]];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (les2[i] == -1) {
            suf[i] = (n - i) * (ll)a[i];
        } else {
            suf[i] = (les2[i] - i) * (ll)a[i] + suf[les2[i]];
        }
    }

    int best = 0;
    for (int i = 1; i < n; i++) {
        if (f(i) > f(best)) {
            best = i;
        }
    }

    vector<int> ans(n);
    ans[best] = a[best];
    int cur = a[best];

    for (int j = best - 1; j >= 0; j--) {
        cur = min(a[j], cur);
        ans[j] = cur;
    }

    cur = a[best];
    for (int j = best + 1; j < n; j++) {
        cur = min(a[j], cur);
        ans[j] = cur;
    }

    for (int i : ans) cout << i << ' '; cout << '\n';
    return 0;
}
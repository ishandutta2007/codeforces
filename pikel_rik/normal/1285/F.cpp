#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5;

int mu[N + 1];
vector<int> divisors[N + 1];

void compDivisors() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void compMu() {
    for (int i = 1; i <= N; i++) {
        mu[i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        if (divisors[i].size() == 2) {
            for (int j = i; j <= N; j += i) {
                mu[j] = -mu[j];
            }
        } else if (divisors[i].size() == 3) {
            for (int j = i; j <= N; j += i) {
                mu[j] = 0;
            }
        }
    }
}

int n, a[N], cnt[N + 1];
vector<int> g[N + 1];

void add(int x) {
    for (int d : divisors[x]) {
        cnt[d]++;
    }
}

void remove(int x) {
    for (int d : divisors[x]) {
        cnt[d]--;
    }
}

int count(int x) {
    int c = 0;
    for (int d : divisors[x]) {
        c += mu[d] * cnt[d];
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compDivisors();
    compMu();

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int d : divisors[a[i]]) {
            g[d].push_back(a[i]);
        }
    }

    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        if (g[i].empty()) continue;

        sort(g[i].begin(), g[i].end(), greater<>());
        stack<int> st;

        for (int x : g[i]) {
            x /= i;
            while (!st.empty() and count(x)) {
                if (__gcd(x, st.top()) == 1) {
                    ans = max(ans, (ll)i * x * st.top());
                }
                remove(st.top());
                st.pop();
            }
            st.push(x);
            add(x);
        }

        while (!st.empty()) {
            remove(st.top());
            st.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)3e5 + 7;

int a[dd], b[dd], x[dd], y[dd];
ll sumS[dd], sumP[dd], ans[dd];

struct Q {
    int a, b, i;
} T[dd];

int solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        T[i] = { x[i], y[i], i };
    }
    sort(T, T + n, [](Q f, Q s) {
        return f.a - f.b < s.a - s.b;
    });
    sumS[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        sumS[i] = sumS[i + 1] + T[i].b;
    }
    sumP[0] = T[0].a;
    for (int i = 1; i < n; ++i) {
        sumP[i] = sumP[i - 1] + T[i].a;
    }
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        ans[T[i].i] = sumS[j] + 1ll * (n - j) * T[i].a;
        ans[T[i].i] += sumP[j - 1] + 1ll * j * T[i].b;
    }
    set<pair<int, int>> used;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (used.find({ a, b }) != used.end()) {
            continue;
        }
        used.insert({ a, b });
        used.insert({ b, a });
        ans[a] -= min(x[a] + y[b], x[b] + y[a]);
        ans[b] -= min(x[a] + y[b], x[b] + y[a]);
    }
    for (int i = 0; i < n; ++i) {
        ans[i] -= x[i] + y[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
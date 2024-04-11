#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<long> d(n); //    
    vector<int> from(n); //  
    vector<bool> z(n); //   ?
    long res = 0;
    for (int i = 0; i < n; i++) {
        d[i] = c[i];
        from[i] = -1;
    }

    vector<int> st;
    vector<pair<int, int>> cab;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (z[j]) continue;
            if (v == -1 || d[j] < d[v]) v = j;
        }
        res += d[v];
        z[v] = true;

        if (from[v] == -1) {
            st.push_back(v);
        } else {
            cab.push_back({from[v], v});
        }

        for (int j = 0; j < n; j++) {
            long dd = (long)(k[v] + k[j]) * (abs(x[v] - x[j]) + abs(y[v] -  y[j]));
            if (dd < d[j]) {
                d[j] = dd;
                from[j] = v;
            }
        }
    }
    cout << res << "\n";
    cout << st.size() << "\n";
    for (int x : st) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    cout << cab.size() << "\n";
    for (auto e : cab) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }

    return 0;
}
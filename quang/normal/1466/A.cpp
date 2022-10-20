#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &u : a) cin >> u;
        set<int> s;
        for (int u : a) {
            for (int v : a) {
                if (u < v) s.insert(v - u);
            }
        }
        cout << s.size() << '\n';
    }
    return 0;
}
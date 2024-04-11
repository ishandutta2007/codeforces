#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c];
vector<int> x, y;
vector<pair<int, int> > sol;
bool v[c], s;
void dfs(int a) {
    v[a]=true;
    if (s) {
        y.push_back(a);
    } else {
        x.push_back(a);
    }
    if (!v[t[a]]) {
        dfs(t[a]);
    }
}
void add(int a, int b) {
    swap(t[a], t[b]);
    t[a]*=-1, t[b]*=-1;
    sol.push_back({a, b});
}
void solve() {
    int s0=x.size(), s1=y.size();
    for (int i=0; i<s0; i++) {
        add(x[i], y[0]);
    }
    for (int j=1; j<s1; j++) {
        add(x[0], y[j]);
    }
    add(x[0], y[0]);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
            s=!s;
            if (!s) {
                solve();
                x.clear(), y.clear();
            }
        }
    }
    if (s) {
        int si=x.size();
        if (si<3) {
            y.push_back(1);
            solve();
        } else {
            add(x[0], x[1]);
            for (int i=2; i<si-1; i++) {
                add(x[0], x[i]);
            }
            add(x[1], x[si-1]), add(x[0], x[si-1]), add(x[0], x[1]);
        }
    }
    cout << sol.size() << "\n";
    for (auto i:sol) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
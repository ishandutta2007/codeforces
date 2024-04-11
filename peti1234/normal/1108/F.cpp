#include <bits/stdc++.h>

using namespace std;
int n, m, ans, ki[200005];
map<int, vector<pair<int, int> > > p;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        p[c].push_back({a, b});
    }
    for (auto s:p) {
        for (auto x:s.second) {
            if (holvan(x.first)==holvan(x.second)) ans--;
        }
        for (auto x:s.second) {
            int a=holvan(x.first), b=holvan(x.second);
            if (a==b) ans++;
            else ki[a]=b;
        }
    }
    cout << ans << "\n";
    return 0;
}
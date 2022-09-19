#include <bits/stdc++.h>

using namespace std;
int n, m, k;
vector<pair<int, char> > ans;
void add(int a, char b) {
    a=min(a, k);
    if (a) {
        ans.push_back({a, b});
        k-=a;
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<n; i++) {
        add(1, 'D');
        add(m-1, 'R');
        add(m-1, 'L');
    }
    add(n-1, 'U');
    for (int i=1; i<m; i++) {
        add(1, 'R');
        add(n-1, 'D');
        add(n-1, 'U');
    }
    add(m-1, 'L');
    if (k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}
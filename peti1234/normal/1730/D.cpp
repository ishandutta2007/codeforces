#include <bits/stdc++.h>

using namespace std;
void solve() {
    set<string> s;
    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        char x=a[i], y=b[n-1-i];
        if (x>y) swap(x, y);
        string f;
        f+=x, f+=y;
        if (s.count(f)) s.erase(f);
        else s.insert(f);
    }
    bool jo=(s.size()<=1);
    for (auto x:s) {
        if (x[0]!=x[1]) jo=0;
    }
    cout << (jo ? "YES" : "NO") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
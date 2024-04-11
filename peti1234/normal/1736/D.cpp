#include <bits/stdc++.h>

using namespace std;

int n, t[200005];
void solve() {
    cin >> n;
    n*=2;
    int db=0;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        t[i]=(c=='1');
        db+=t[i];
    }
    if (db%2) {
        cout << -1 << "\n";
        return;
    }
    int s=0;
    vector<int> sz;
    for (int i=1; i<=n; i+=2) {
        if (t[i]!=t[i+1]) {
            if (s%2==t[i]) sz.push_back(i);
            else sz.push_back(i+1);
            s++;
        }
    }
    cout << s << " ";
    for (auto x:sz) cout << x << " ";
    cout << "\n";
    for (int i=1; i<=n; i+=2) cout << i << " ";
    cout << "\n";
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
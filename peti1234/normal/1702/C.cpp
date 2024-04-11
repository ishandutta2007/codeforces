#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k;
    map<int, int> el, ut;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (el.find(x)==el.end()) el[x]=i;
        ut[x]=i;
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (el.find(a)!=el.end() && el.find(b)!=el.end() && el[a]<ut[b]) cout << "YES\n";
        else cout << "NO\n";
    }
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
/*
1
stringology
*/
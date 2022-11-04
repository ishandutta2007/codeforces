#include <bits/stdc++.h>

using namespace std;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int mx = 0;
    multiset <int> s;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        mx = max(mx, x);
    }
    for(i = 1; i <= m; i++) {
        int x = *s.begin();
        s.erase(s.begin());
        s.insert(x + 1);
    }
    cout << *prev(s.end()) << " ";
    cout << mx + m;
    //cin.close();
    //cout.close();
    return 0;
}
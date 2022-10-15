#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, m, k;
map<int, int> a;
map<int, int> b;
set<int> y;

int main() {
    cin >> n >> m >> k;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
        y.insert(t);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        b[t]++;
        y.insert(t);
    }
    
    set<int>::reverse_iterator it;
    int at = 0, bt = 0;
    bool tt = false;
    for (it = y.rbegin(); it != y.rend(); it++) {
        int v = *it;
        at += a[v];
        bt += b[v];
        if (at > bt) {
            tt = true;
            break;
        }
    }
    if (tt) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
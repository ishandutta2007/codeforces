#include <bits/stdc++.h>

using namespace std;
bool solve() {
    int a, b;
    cin >> a >> b;
    string x, y;
    cin >> x >> y;
    while (y.size()>1 && x.back()==y.back()) {
        x.pop_back(), y.pop_back();
    }
    if (y.size()>1) {
        return false;
    }
    for (auto p:x) {
        if (p==y[0]) {
            return true;
        }
    }
    return false;
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}
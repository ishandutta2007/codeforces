#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, bool> a;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string u;
        cin >> u;
        if (a[u]) {
            puts("YES");
        } else {
            puts("NO");
            a[u] = 1;
        }
    }
    return 0;
}
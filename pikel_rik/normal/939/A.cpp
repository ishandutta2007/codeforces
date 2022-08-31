#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    vector<int> v(n+1);
    int c = 0;

    for (int i = 1; i <= n; i++) {
        if (f[f[f[i]]] == i)
            c += 1;
    }

    if (c > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
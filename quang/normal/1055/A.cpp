#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n ,s;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++) {
        cin >> b[j];
    }
    if (a[1] == 0) {
        cout << "NO\n";
        return 0;
    }
    if (a[s] == 1) {
        cout << "YES\n";
        return 0;
    }
    if (b[s] == 0) {
        cout << "NO\n";
        return 0;
    }
    for (int i = s + 1; i <= n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
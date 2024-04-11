#include <iostream>

using namespace std;
const int N = 1e5;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 1; i != n; i += a[i])
        if (i == t) {
            cout << "YES\n";
            return 0;
        }
    cout << (t == n ? "YES\n" : "NO\n");
    return 0;
}
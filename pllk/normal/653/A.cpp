#include <iostream>

using namespace std;

int n;
int t[55];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int a = 1; a <= n; a++)
    for (int b = a+1; b <= n; b++)
    for (int c = b+1; c <= n; c++) {
        if (t[a] == t[b]) continue;
        if (t[a] == t[c]) continue;
        if (t[b] == t[c]) continue;
        int x1 = min(t[a],min(t[b],t[c]));
        int x2 = max(t[a],max(t[b],t[c]));
        if (x2-x1 > 2) continue;
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}
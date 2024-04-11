#include <bits/stdc++.h>

using namespace std;
int n;
void solve(int n) {
    if (n==4) {
        cout << "4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24";
        return;
    }
    if (n==5) {
        cout << "5 * 3 = 15\n2 * 4 = 8\n15 + 8 = 23 \n23 + 1 = 24\n";
        return;
    }
    cout << n << " - " << n-1 << " = 1\n" << "1 * 1 = 1\n";
    solve(n-2);
}
int main()
{
    cin >> n;
    if (n<=3) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        solve(n);
    }
    return 0;
}
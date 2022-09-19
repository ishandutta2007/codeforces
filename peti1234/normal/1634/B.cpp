#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        long long db=0;
        for (int i=1; i<=n+2; i++) {
            long long x;
            cin >> x;
            db+=x%2;
        }
        cout << (db%2 ? "Bob" : "Alice") << "\n";
    }
    return 0;
}
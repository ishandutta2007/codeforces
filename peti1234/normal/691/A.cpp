#include <bits/stdc++.h>

using namespace std;
int n, db, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        db+=x;
    }
    cout << (n==1 && db==1 || n>1 && db==n-1 ? "YES" : "NO") << "\n";
    return 0;
}
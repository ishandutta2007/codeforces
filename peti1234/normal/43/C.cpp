#include <bits/stdc++.h>

using namespace std;
int t[3], n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        t[x%3]++;
    }
    cout << min(t[1], t[2])+t[0]/2 << "\n";
    return 0;
}
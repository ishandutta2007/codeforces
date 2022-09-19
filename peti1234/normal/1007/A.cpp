#include <bits/stdc++.h>

using namespace std;
int n, maxi;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        m[x]++;
        maxi=max(maxi, m[x]);
    }
    cout << n-maxi << "\n";
    return 0;
}
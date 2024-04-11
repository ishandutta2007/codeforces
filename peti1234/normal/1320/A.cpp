#include <bits/stdc++.h>

using namespace std;
long long p[600001], maxi;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        p[x-i+n]+=x;
        maxi=max(maxi, p[x-i+n]);
    }
    cout << maxi << "\n";
    return 0;
}
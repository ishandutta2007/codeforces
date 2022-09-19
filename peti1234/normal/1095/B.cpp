#include <bits/stdc++.h>

using namespace std;
int n, t[100005];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    cout << min(t[n]-t[2], t[n-1]-t[1]) << "\n";
    return 0;
}
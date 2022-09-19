#include <bits/stdc++.h>

using namespace std;
int n, maxi, pos, t[200005];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    t[n+1]=t[n]+10;
    for (int i=1; i<=n; i++) {
        while (t[pos]-t[i]<=5) pos++;
        maxi=max(maxi, pos-i);
    }
    cout << maxi << "\n";
    return 0;
}
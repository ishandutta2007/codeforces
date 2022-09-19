#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, t[c], pref[c], pos, mini=1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+t[i];
    }
    for (int i=k; i<=n; i++) {
        if (pref[i]-pref[i-k]<mini) {
            pos=i-k+1;
            mini=pref[i]-pref[i-k];
        }
    }
    cout << pos << "\n";
    return 0;
}
/*
7 3
1 2 6 1 1 7 1
*/
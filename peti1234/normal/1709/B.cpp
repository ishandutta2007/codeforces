#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, m, t[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+abs(t[i]-t[i-1]);
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << (abs(pref[a]-pref[b])+t[a]-t[b])/2 << "\n";
    }
    return 0;
}
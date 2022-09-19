#include <bits/stdc++.h>

using namespace std;
long long w, s, n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s >> n >> k;
        if (s==k) {
            cout << "YES\n";
            continue;
        }
        long long ert=n-n/k+n/k*(k+1);
        cout << (ert<=s ? "NO" : "YES") << "\n";
    }
    return 0;
}
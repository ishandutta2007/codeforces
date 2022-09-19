#include <bits/stdc++.h>

using namespace std;
int w, n, d, t[102];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> d;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        cout << (min(t[1]+t[2], t[n])<=d ? "YES" : "NO") << "\n";
    }
    return 0;
}
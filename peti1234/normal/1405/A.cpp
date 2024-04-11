#include <bits/stdc++.h>

using namespace std;
int w, n, t[102];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=n; i>=1; i--) cout << t[i] << " ";
        cout << "\n";
    }
    return 0;
}
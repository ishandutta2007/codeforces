#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, da=0, db=0, k=0;
        cin >> n;
        string a, b;
        cin >> a >> b;
        for (int i=0; i<n; i++) {
            if (a[i]=='1') da++;
            if (b[i]=='1') db++;
            if (a[i]!=b[i]) k++;
        }
        //cout << "valasz................ ";
        if (da==0 || db==0) {
            cout << (k==0 ? 0 : -1) << "\n";
            continue;
        }
        if (da==db && da+db==n+1) {
            cout << min(k, n-k) << "\n";
            continue;
        }
        if (da==db) {
            cout << k << "\n";
            continue;
        }
        if (da+db==n+1) {
            cout << n-k << "\n";
            continue;
        }
        cout << -1 << "\n";

    }
    return 0;
}
/*
1
9
100010111
101101100
*/
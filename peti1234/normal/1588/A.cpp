#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        vector<int> a, b;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        int baj=0;
        for (int i=0; i<n; i++) {
            if (a[i]>b[i] || a[i]+1<b[i]) baj=1;
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}
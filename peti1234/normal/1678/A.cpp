#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, db=0;
        cin >> n;
        vector<int> sz;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (x==0) db++;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        if (!db) {
            bool s=0;
            for (int i=1; i<n; i++) {
                if (sz[i]==sz[i-1]) {
                    s=1;
                }
            }
            if (!s) {
                db--;
            }
        }
        cout << n-db << "\n";
    }
    return 0;
}
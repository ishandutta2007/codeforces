#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> left(n+1);
        vector<int> right(n+1);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (i <= l) left[x]++;
            else right[x]++;
        }
        for (int i = 1; i <= n; i++) {
            int u = min(left[i],right[i]);
            left[i] -= u;
            right[i] -= u;
        }
        int lc = 0, rc = 0;
        int lp = 0, rp = 0;
        for (int i = 1; i <= n; i++) {
            lc += left[i];
            rc += right[i];
            lp += left[i]/2*2;
            rp += right[i]/2*2;
        }
        int c = 0;
        c += min(lc,rc);
        lc -= c;
        rc -= c;
        if (lc) {
            int u = min(lc,lp);
            c += u/2;
            lc -= u;
            c += lc;
        }
        if (rc) {
            int u = min(rc,rp);
            c += u/2;
            rc -= u;
            c += rc;
        }
        cout << c << "\n";
    }
}
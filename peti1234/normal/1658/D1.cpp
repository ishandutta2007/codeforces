#include <bits/stdc++.h>

using namespace std;
int solve(int l, int r, set<int> s) {
    if (l%2==r%2) {
        int ans=0;
        for (int i=l; i<=r; i++) {
            ans=ans^i;
        }
        for (auto x:s) {
            ans=ans^x;
        }
        return ans;
    }
    if (l%2==0) {
        set<int> s2;
        for (auto x:s) {
            if (x%2==0) {
                s2.insert(x/2);
            }
        }
        return 2*solve(l/2, r/2, s2);
    }
    for (auto x:s) {
        if (s.find(x^1)==s.end()) {
            int ert=x^l;
            bool baj=0;
            for (int i=l; i<=r; i++) {
                if (s.find(i^ert)==s.end()) {
                    baj=1;
                }
            }
            if (!baj) {
                return ert;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int l, r;
        set<int> s;
        cin >> l >> r;
        for (int i=1; i<=r-l+1; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        cout << solve(l, r, s) << "\n";
    }
    return 0;
}
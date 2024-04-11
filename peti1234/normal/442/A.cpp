#include <bits/stdc++.h>

using namespace std;
int n, mini=10;
vector<int> sz;
string s="12345RGBYW", p;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> p;
        int ert=0;
        for (int j=0; j<2; j++) {
            for (int k=0; k<10; k++) {
                if (p[j]==s[k]) {
                    ert+=(1<<k);
                }
            }
        }
        sz.push_back(ert);
    }
    for (int k=0; k<(1<<10); k++) {
        bool jo=1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (sz[i]!=sz[j] && (sz[i]&k) == (sz[j]&k)) {
                    jo=0;
                }
            }
        }
        if (jo) {
            mini=min(mini, __builtin_popcount(k));
        }
    }
    cout << mini << "\n";
    return 0;
}
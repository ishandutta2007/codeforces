#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, k;
        cin >> n >> k;
        int s[105];
        for (int i=1; i<=n; i++) {
            cin >> s[i];
        }
        vector<pair<int, int> > sz;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back({s[i], x});
        }
        sort(sz.begin(), sz.end());
        for (auto p:sz) {
            if (k>=p.first) {
                k+=p.second;
            }
        }
        cout << k << "\n";
    }
    return 0;
}
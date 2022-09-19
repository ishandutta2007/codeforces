#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, sum=0;
        vector<int> sz;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        if (n==1) {
            cout << 1 << "\n";
            continue;
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n; i++) {
            if (i<2 || sz[i]!=sz[i-2]) sum++;
        }
        cout << (sum+1)/2 << "\n";
    }
    return 0;
}
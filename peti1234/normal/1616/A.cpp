#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        vector<int> sz;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(abs(x));
        }
        sort(sz.begin(), sz.end());
        int ans=0;
        for (int i=0; i<n; i++) {
            if (sz[i]==0 && (i==0 || sz[i]!=sz[i-1]) || (sz[i]!=0 && (i<2 || sz[i]!=sz[i-2]))) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, sum=0;
        cin >> n;
        vector<int> sz;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            sum+=x, sz.push_back(x);
        }
        if (sum==0) cout << "NO\n";
        else {
            cout << "YES\n";
            if (sum<0) sort(sz.begin(), sz.end());
            else sort(sz.rbegin(), sz.rend());
            for (int i:sz) cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}
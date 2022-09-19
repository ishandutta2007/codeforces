#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sz;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        bool baj=0;
        int ter=0;
        n*=4;
        sz.clear();
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        ter=sz[0]*sz[n-1];
        for (int i=1; i<n; i+=2) {
            if (sz[i]!=sz[i-1]) {
                baj=1;
            }
        }
        for (int i=0; i<n/2; i++) {
            if (sz[i]*sz[n-i-1]!=ter) {    
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}
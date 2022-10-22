#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2*n, vector<int>(2*n));
        int cnt=0;
        for (int i=0; i<n; ++i) {
            string s;
            cin >> s;
            for (int j=0; j<n; ++j) {
                if (s[j]=='1') {
                    a[i][j]=a[i+n][j]=a[i][j+n]=a[i+n][j+n]=1;
                    ++cnt;
                }
            }
        }
        for (int i=1; i<2*n; ++i) {
            for (int j=1; j<2*n; ++j) {
                a[i][j]+=a[i-1][j-1];
            }
        }
        int ans=69696969;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int x=a[i+n][j+n]-a[i][j];
                ans=min(ans, n-x+(cnt-x));
            }
        }
        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, ans=0, cnt;
        cin >> n;
        vector<int> sz;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        for (int j=0; j<30; j++) {
            cnt=0;
            for (auto x:sz) {
                if (x & (1<<j)) {
                    cnt++;
                }
            }
            ans=__gcd(ans, cnt);
        }
        for (int i=1; i<=n; i++) {
            if (ans%i==0) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
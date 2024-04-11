#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, k, db[30];
        cin >> n >> k;
        for (int i=0; i<k; i++) db[i]=0;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            for (int j=0; j<k; j++) {
                if (x & (1<<j)) db[j]++;
            }
        }
        int ans=0;
        for (int i=0; i<k; i++) {
            if (2*db[i]>n) ans+=(1<<i);
        }
        //cout << "valasz......... ";
        cout << ans << "\n";
    }
    return 0;
}
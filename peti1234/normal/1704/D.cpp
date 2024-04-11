#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long n, m, pos=0, mini=1e18, maxi=0;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            long long sum=0;
            for (int j=1; j<=m; j++) {
                long long x;
                cin >> x;
                sum+=j*x;
            }
            mini=min(mini, sum);
            if (maxi<sum) {
                pos=i;
                maxi=sum;
            }
        }
        cout << pos << " " << maxi-mini << "\n";
    }
    return 0;
}
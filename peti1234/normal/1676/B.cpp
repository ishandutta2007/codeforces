#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n=0, sum=0, mini=1e9;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sum+=x;
            mini=min(mini, x);
        }
        cout << sum-n*mini << "\n";
    }
    return 0;
}
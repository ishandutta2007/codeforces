#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m, sum=0;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sum+=x;
        }
        cout << max(0, sum-m) << "\n";
    }
    return 0;
}
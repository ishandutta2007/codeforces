#include <bits/stdc++.h>

using namespace std;
long long w, n, t[200005], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int m;
        cin >> m;
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            sum=(sum+x)%n;
        }
        cout << t[sum+1] << "\n";
        sum=0;
    }
    return 0;
}
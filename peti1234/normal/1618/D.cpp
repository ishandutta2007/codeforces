#include <bits/stdc++.h>

using namespace std;
long long w, n, k, t[105], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=1; i<=n-2*k; i++) {
            sum+=t[i];
        }
        for (int i=n-2*k+1; i<=n-k; i++) {
            if (t[i]==t[i+k]) sum++;
        }
        cout << sum << "\n";
        sum=0;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
long long w, n, k, x, sum, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> sum, ans=0;
        for (int i=1; i<n; i++) {
            cin >> x;
            ans=max(ans, 100*x-k*sum);
            sum+=x;
        }
        cout << (ans+k-1)/k << "\n";
    }
    return 0;
}
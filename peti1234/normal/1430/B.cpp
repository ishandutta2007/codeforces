#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, sum, t[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, sum=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=n-k; i<=n; i++) sum+=t[i];
        cout << sum << "\n";
    }
    return 0;
}
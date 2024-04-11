#include <bits/stdc++.h>

using namespace std;
long long w, n, k, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, ans=0;
        long long x=k/(n-1);
        ans=x*n, k%=(n-1);
        if (!k) cout << ans-1 << "\n";
        else cout << ans+k << "\n";
    }
    return 0;
}
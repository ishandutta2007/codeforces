#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long n, ans=0, x;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x;
            long long ert=(x==0 ? 2 : 1);
            ans+=ert*i*(n-i+1);
        }
        cout << ans << "\n";
    }
    return 0;
}
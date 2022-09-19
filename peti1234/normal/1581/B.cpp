#include <bits/stdc++.h>

using namespace std;
long long w, n, m, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        long long s=(n==1 ? 0 : n*(n-1)/2==m ? 1 : 2);
        cout << (m>=n-1 && n*(n-1)>=2*m && s<k-1 ? "YES" : "NO") << "\n";
    }
    return 0;
}
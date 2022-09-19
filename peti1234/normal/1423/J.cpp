#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7, w, n;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n;
        n=(n/2+1)%(2*mod);
        cout << (n/2+n%2)*(n/2+1)%mod << "\n";
    }
    return 0;
}
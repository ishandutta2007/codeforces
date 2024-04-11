#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        long long n, k, f;
        cin >> n >> k, f=(k+1)*k/2;
        if (k<n) cout << f << "\n";
        else cout << (n-1)*n/2+1 << "\n";

    }
    return 0;
}
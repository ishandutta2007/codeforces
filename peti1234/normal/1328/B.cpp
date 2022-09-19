#include <bits/stdc++.h>

using namespace std;
long long w, n, k, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k;
        a=n-1, b=n, k--;
        while(n-a<=k) k-=n-a, a--;
        while(k>0) k--, b--;
        for (int i=1; i<=n; i++) {
            if (i!=a && i!=b) cout << 'a';
            else cout << 'b';
        }
        cout << "\n";
    }
    return 0;
}
// Knny volt, fleg gy, hogy kicsi volt a korlt, s gy nem kellett szmolgatni.
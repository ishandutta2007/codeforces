#include <bits/stdc++.h>

using namespace std;
int w, n, a, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> a, p=0;
        for (int i=1; i<n; i++) {
            int x; cin >> x;
            if (a!=x) p++;
        }
        if (!p) cout << n << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}
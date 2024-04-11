#include <bits/stdc++.h>

using namespace std;
int w, a, b, n;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, a=0, b=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (i<=2) a+=x;
            if (i==n) b+=x;
        }
        if (a<=b) cout << 1 << " " << 2 << " " << n << "\n";
        else cout << "-1\n";
    }
    return 0;
}
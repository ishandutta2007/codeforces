#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        int f=n/2;
        if (a+(b>a)>f+1 || b-(a<b)<f) cout << -1 << "\n";
        else {
            for (int i=f+1; i<=n; i++) if (i!=b) cout << i << " ";
            if (a<=f) cout << a << " ";
            for (int i=1; i<=f; i++) if (i!=a) cout << i << " ";
            if (b>f) cout << b << " ";
            cout << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, n, pr, p;
bool x=true;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, x=1, pr=n+1;
        for (int i=1; i<=n; i++) {
            cin >> p;
            if (p-1>pr) x=0;
            pr=p;
        }
        if (x) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
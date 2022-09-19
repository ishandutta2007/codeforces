#include <bits/stdc++.h>

using namespace std;
int w, n, m, x, y, sum, el, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m >> x >> y, sum=0;
        for (int i=1; i<=n; i++) {
            el=0;
            for (int j=1; j<=m; j++) {
                char c; p=0;
                cin >> c;
                if (c=='.') p=1;
                if (el && p && 2*x>y) sum+=y, el=0, p=0;
                if (el) sum+=x;
                el=p;
            }
            if (el) sum+=x;
        }
        cout << sum << "\n";
    }
    return 0;
}
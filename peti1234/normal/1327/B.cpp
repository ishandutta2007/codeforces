#include <bits/stdc++.h>

using namespace std;
int w, n, x, y;
bool v[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        x=0;
        for (int i=1; i<=n; i++) {
            v[i]=false;
        }
        for (int i=1; i<=n; i++) {
            cin >> y;
            bool c=false;
            for (int i=1; i<=y; i++) {
                int a;
                cin >> a;
                if (!v[a] && !c) {
                    v[a]=true, c=true;
                }
            }
            if (!c) x=i;
        }
        for (int i=1; i<=n; i++) if (!v[i]) y=i;
        if (x) cout << "IMPROVE" << "\n" << x << " " << y << "\n";
        else cout << "OPTIMAL" << "\n";
    }
    return 0;
}
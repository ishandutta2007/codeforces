#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, m;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[b]=1;
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                for (int j=1; j<=n; j++) {
                    if (i!=j) {
                        cout << i << " " << j << "\n";
                    }
                }
                break;
            }
        }
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
    }
    return 0;
}
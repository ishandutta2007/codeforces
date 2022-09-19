#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        int sok=1e9, kis, nagy, ke, ne, spec;
        cin >> kis >> nagy >> spec;
        ke=spec, ne=spec;
        cout << spec << "\n";
        for (int i=1; i<n; i++) {
            int l, r, c;
            cin >> l >> r >> c;
            if (l<kis) {
                kis=l, ke=sok, spec=2*sok;
            }
            if (r>nagy) {
                nagy=r, ne=sok, spec=2*sok;
            }
            if (kis==l) {
                ke=min(ke, c);
            }
            if (nagy==r) {
                ne=min(ne, c);
            }
            if (kis==l && nagy==r) {
                spec=min(spec, c);
            }

            cout << min(ke+ne, spec) << "\n";
        }
    }
    return 0;
}
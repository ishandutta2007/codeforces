#include <bits/stdc++.h>

using namespace std;
const int x=102;
int w, a[x], b[x], c[x], fi, el, n;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) cin >> b[i];
        for (int i=1; i<=n; i++) cin >> c[i];
        cout << a[1] << " ", el=a[1], fi=a[1];
        for (int i=2; i<=n; i++) {
            if (a[i]!=fi && a[i]!=el) cout << a[i] << " ", el=a[i];
            else if (b[i]!=fi && b[i]!=el) cout << b[i] << " ", el=b[i];
            else cout << c[i] << " ", el=c[i];
        }
        cout << "\n";
    }
    return 0;
}
// a
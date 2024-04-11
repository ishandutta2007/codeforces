#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, t[c], ans[c];
void solve(int a, int b) {
    if (a>=b) {
        return;
    }
    int pos=a;
    for (int i=a; i<=b; i++) {
        if (t[i]>=t[pos]) {
            pos=i;
        }
    }
    for (int i=a; i<=b; i++) {
        if (i!=pos) {
            ans[i]++;
        }
    }
    solve(a, pos-1), solve(pos+1, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            ans[i]=0;
        }
        solve(1, n);
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
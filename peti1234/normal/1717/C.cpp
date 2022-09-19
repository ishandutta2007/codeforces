#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, a[c], b[c];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    bool jo=1;
    int pos=-1;
    for (int i=0; i<n; i++) {
        if (a[i]>b[i]) jo=0;
        int kov=b[(i+1)%n];
        if (a[i]<b[i] && b[i]>kov+1) jo=0;
    }
    cout << (jo ? "YES" : "NO") << "\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
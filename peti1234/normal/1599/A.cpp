#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], kis, nagy, ans[c];
bool v[c], h[c];
void pb(int pos, bool id, bool p) {
    ans[pos]=(id ? t[nagy] : t[kis]);
    h[pos]=p;
    (id ? nagy-- : kis++);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        v[i]=(c=='L');
    }
    kis=1, nagy=n;
    if (n%2) {
        pb(n, 1, v[n]);
    }
    for (int i=n/2*2; i>0; i-=2) {
        bool v1=(v[i-1]!=v[i-2]), v2=(v[i]!=v[i-1]);
        if (v1 && v2) {
            pb(i, 1, v[i]);
            pb(i-1, 1, !v[i]);
        }
        if (v1 && !v2) {
            pb(i, 0, !v[i-1]);
            pb(i-1, 1, v[i-1]);
        }
        if (!v1 && v2) {
            pb(i, 1, v[i]);
            pb(i-1, 0, !v[i]);
        }
        if (!v1 && !v2) {
            pb(i-1, 1, v[i-1]);
            pb(i, 1, !v[i-1]);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " " << (h[i] ? "L" : "R") << "\n";
    }
    return 0;
}
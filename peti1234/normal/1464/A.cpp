#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, m, ki[c], ans;
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    } else ans++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, ans=0;
        for (int i=1; i<=n; i++) {
            ki[i]=0;
        }
        for (int i=1; i<=m; i++) {
            int x, y; cin >> x >> y;
            if (x!=y) {
                ans++;
                unio(x, y);
            }
        }
        //cout << "valasz ";
        cout << ans << "\n";
    }
    return 0;
}
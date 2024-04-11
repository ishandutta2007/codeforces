#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int w, n, mini, maxi, t[c], ki[c];
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int a, int b) {
    int aa=holvan(a), bb=holvan(b);
    if (aa!=bb) {
        cout << a << " " << b << "\n";
        ki[aa]=bb;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, mini=1e9, maxi=0;
        for (int i=1; i<=n; i++) cin >> t[i], maxi=max(maxi, t[i]), mini=min(mini, t[i]), ki[i]=0;
        if (maxi==mini) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                for (int j=i+1; j<=n; j++) {
                    if (t[i]!=t[j]) unio(i, j);
                }
            }
        }

    }
    return 0;
}
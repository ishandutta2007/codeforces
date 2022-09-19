#include <bits/stdc++.h>

using namespace std;
int n, t[200005], db, pos, el, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]<0) db++;
    }
    if (db%2) {
        for (int i=1; i<=n; i++) {
            if (t[i]<0 && (pos==0 || t[i]>t[pos])) pos=i;
        }
    }
    el=pos;
    for (int i=1; i<=n; i++) {
        if (t[i]==0) {
            if (el) {
                s++;
                cout << 1 << " " << el << " " << i << "\n";
            }
            el=i;
        }
    }
    if (el && s<n-1) {
        cout << 2 << " " << el << "\n";
    }
    el=0;
    for (int i=1; i<=n; i++) {
        if (i!=pos && t[i]!=0) {
            if (el) {
                cout << 1 << " " << el << " " << i << "\n";
            }
            el=i;
        }
    }
    return 0;
}
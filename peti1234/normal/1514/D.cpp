#include <bits/stdc++.h>

using namespace std;
const int c=300002, k=402, s=750;
int n, q, t[c], db[c], kom[k][c], nagydb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        db[t[i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (db[t[i]]>=s) {
            nagydb++;
            for (int j=1; j<=n; j++) {
                kom[nagydb][j]=kom[nagydb][j-1]+(t[j]==t[i]);
            }
        }
        db[t[i]]=0;
    }
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        int maxi=0, h=r-l+1;
        if (h<=2*s) {
            for (int j=l; j<=r; j++) {
                db[t[j]]++;
                maxi=max(maxi, db[t[j]]);
            }
            for (int j=l; j<=r; j++) {
                db[t[j]]=0;
            }
        } else {
            for (int j=1; j<=nagydb; j++) {
                maxi=max(maxi, kom[j][r]-kom[j][l-1]);
            }
        }
        cout << max(1, 2*maxi-h) << "\n";
    }
    return 0;
}
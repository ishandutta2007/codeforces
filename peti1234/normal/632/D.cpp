#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, pos=1, db[c], t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]<c) {
            db[t[i]]++;
        }
    }
    for (int i=c-1; i>=1; i--) {
        for (int j=2*i; j<c; j+=i) {
            db[j]+=db[i];
            if (j<=m && (db[j]>db[pos] || (db[j]==db[pos] && j<pos))) {
                pos=j;
            }
        }
    }
    cout << pos << " " << db[pos] << "\n";
    for (int i=1; i<=n; i++) {
        if (pos%t[i]==0) {
            cout << i << " ";
        }
    }
    return 0;
}
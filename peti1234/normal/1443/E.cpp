#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=15;
long long n, q, h, db, fakt[k+1], t[c], kom[c], p, o=0;
bool v[k+1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q, h=max(o, n-k), db=n-h;
    fakt[0]=1;
    for (int i=1; i<=db; i++) {
        fakt[i]=fakt[i-1]*i;
    }
    for (int i=1; i<=n; i++) {
        t[i]=i, kom[i]=kom[i-1]+i;
    }
    for (int j=1; j<=q; j++) {
        int x;
        cin >> x;
        if (x==1) {
            int l, r; cin >> l >> r;
            cout << kom[r]-kom[l-1] << "\n";
        } else {
            int y; cin >> y;
            p+=y;
            for (int i=1; i<=db; i++) v[i]=0;
            long long ert=p, pl;
            for (int i=1; i<=db; i++) {
                pl=fakt[db-i];
                int pos=1;
                while(v[pos] || ert>=pl) {
                    if (!v[pos]) ert-=pl;
                    pos++;
                }
                t[i+h]=pos+h, v[pos]=1;
                kom[i+h]=kom[i+h-1]+t[i+h];
            }
        }
    }
    return 0;
}
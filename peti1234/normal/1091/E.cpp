#include <bits/stdc++.h>

using namespace std;
const int c=500002;
long long n, db[c], lo, hi, ndb, nsum, kdb, koz, ksum, cel, oel, pos=-1, o=0;
bool par;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, n++, hi=n+1;
    for (int i=1; i<n; i++) {
        int x; cin >> x;
        db[x]++;
        if (x%2) par=1-par;
    }
    for (int i=n; i>=0; i--) {
        ndb+=db[i];
        nsum+=db[i]*i;
        while(pos+1<i && pos<ndb) {
            pos++;
            kdb+=db[pos];
            ksum+=db[pos]*pos;
        }
        koz=n-1-kdb-ndb;
        if (kdb+ndb<n) {
            oel=ndb*(ndb-1)+ndb*(koz)+ksum;
            cel=nsum-oel;
            //cout << "lehet " << i << " " << oel << " " << cel << endl;
            if (cel>ndb) {
                hi=-1, lo=n+1;
            }
            lo=max(lo, cel);
            cel-=2*ndb+koz;
            hi=min(hi, -cel);
        }
    }
    hi=max(hi, o);
    if (lo%2!=par) lo++;
    if (hi%2!=par) hi--;
    if (lo>hi) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=lo; i<=hi; i+=2) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
/*
3
3 3 3
*/
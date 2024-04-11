#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int w, n, q, db[c], t[c], maxi, paros, nm[c], sm[c];
int main()
{
    nm[1]=1;
    for (int i=2; i<c; i++) {
        if (!sm[i]) {
            for (int j=i; j<c; j+=i) {
                sm[j]=i;
                nm[j]=(i*nm[j/i]);
                if ((j/i)%i==0) nm[j]=nm[j/i/i];
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, paros=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i], t[i]=nm[t[i]];
            db[t[i]]++;
            maxi=max(maxi, db[t[i]]);
        }
        paros=db[1];
        for (int i=1; i<=n; i++) {
            if (t[i]!=1 && db[t[i]]%2==0) {
                paros+=db[t[i]];
                db[t[i]]--;
            }
        }
        cin >> q;
        while(q--) {
            long long x; cin >> x;
            if (x==0) {
                cout << maxi << "\n";
            } else {
                cout << max(maxi, paros) << "\n";
            }
        }
        for (int i=1; i<=n; i++) {
            db[t[i]]=0;
        }
    }
    return 0;
}
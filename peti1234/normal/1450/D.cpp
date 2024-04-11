#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, db[c], t[c], kezd, veg, sp, ert, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, kezd=1, veg=n, ert=0, sp=1, pos=1;
        for (int i=1; i<=n; i++) db[i]=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
            if (db[t[i]]>1) sp=0;
        }
        while(true) {
            if (db[pos]) ert++;
            if (db[pos]>1 || min(t[kezd], t[veg])!=pos) break;
            if (t[kezd]==pos) kezd++;
            if (t[veg]==pos) veg--;
            pos++;
        }
        cout << sp;
        for (int i=2; i<=n; i++) {
            if (i<=n-ert) cout << 0;
            else cout << 1;
        }
        cout << "\n";
    }
    return 0;
}
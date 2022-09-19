#include <bits/stdc++.h>

using namespace std;
const int c=31;
int w, n, db[c], h;
map<int, int> id;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<c; i++) {
        id[1<<i]=i;
    }
    cin >> w;
    while (w--) {
        cin >> n >> h;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[id[x]]++;
        }
        int ans=0;
        while (n>0) {
            ans++;
            int hh=h;
            for (int i=c-1; i>=0; i--) {
                while (db[i] && (1<<i)<=hh) {
                    db[i]--, n--;
                    hh-=(1<<i);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
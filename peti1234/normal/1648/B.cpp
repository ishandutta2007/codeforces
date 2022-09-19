#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, s, db[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        for (int i=1; i<=s; i++) {
            pref[i]=db[i]+pref[i-1];
        }
        bool jo=(db[1]);
        for (int i=2; i<=s; i++) {
            if (db[i]) {
                for (int j=1; i*j<=s; j++) {
                    int cnt=pref[min(s, i*(j+1)-1)]-pref[max(i, i*j-1)];
                    if (cnt && !db[j]) {
                        jo=0;
                    }
                }
            }
        }
        cout << (jo ? "YES" :"NO") <<"\n";
        for (int i=1; i<=s; i++) {
            db[i]=0, pref[i]=0;
        }
    }
    return 0;
}
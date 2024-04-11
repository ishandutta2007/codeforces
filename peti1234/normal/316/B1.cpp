#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, x, t[c], kov[c], ert;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]) {
            kov[t[i]]=i;
        }
    }
    v[0]=true;
    for (int i=1; i<=n; i++) {
        if (!t[i]) {
            int db=0, sp=0, pos=i;
            while(pos) {
                db++;
                if (pos==x) {
                    ert=db, sp=1;
                }
                pos=kov[pos];
            }
            if (!sp) {
                for (int i=n; i>=0; i--) {
                    if (v[i]) {
                        v[i+db]=true;
                    }
                }
            }
        }
    }
    for (int i=0; i<=n; i++) {
        if (v[i]) {
            cout << i+ert << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, f, t[c], t2[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, f=n, n*=2;
    bool alap=1;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t2[i]=t[i];
        if (t[i]!=i) {
            alap=0;
        }
    }
    if (alap) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (i%2) {
            for (int j=1; j<=n; j+=2) {
                swap(t[j], t[j+1]);
            }
            for (int j=1; j<=f; j++) {
                swap(t2[j], t2[j+f]);
            }
        } else {
            for (int j=1; j<=n; j+=2) {
                swap(t2[j], t2[j+1]);
            }
            for (int j=1; j<=f; j++) {
                swap(t[j], t[j+f]);
            }
        }
        bool jo=1, jo2=1;
        for (int i=1; i<=n; i++) {
            if (t[i]!=i) {
                jo=0;
            }
            if (t2[i]!=i) {
                jo2=0;
            }
        }
        if (jo || jo2) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
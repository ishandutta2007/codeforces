#include <bits/stdc++.h>

using namespace std;
const int c=2000005;
int n, edb, t[1005], ans;
bool pr[c];
int main()
{
    pr[1]=1;
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]==1) {
            edb++;
        }
    }
    if (edb>=2) {
        for (int i=1; i<=n; i++) {
            if (t[i]!=1 && !pr[t[i]+1]) {
                cout << edb+1 << "\n";
                for (int j=1; j<=edb; j++) cout << 1 << " ";
                cout << t[i] << "\n";
                return 0;
            }
        }
        cout << edb << "\n";
        for (int i=1; i<=edb; i++) {
            cout << 1 << " ";
        }
        cout << "\n";
    } else {
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (!pr[t[i]+t[j]]) {
                    cout << 2 << "\n" << t[i] << " " << t[j] << "\n";
                    return 0;
                }
            }
        }
        cout << 1 << "\n" << t[1] << "\n";
    }
    return 0;
}
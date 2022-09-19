#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, bal[c], jobb[c], valasz[c];
bool baj=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> bal[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> jobb[i];
    }
    for (int i=1; i<=n; i++) {
        valasz[i]=n-bal[i]-jobb[i];
    }
    for (int i=1; i<=n; i++) {
        int baldb=0, jobbdb=0;
        for (int j=1; j<i; j++) {
            if (valasz[j]>valasz[i]) {
                baldb++;
            }
        }
        for (int j=i+1; j<=n; j++) {
            if (valasz[j]>valasz[i]) {
                jobbdb++;
            }
        }
        if (baldb!=bal[i] || jobbdb!=jobb[i]) {
            baj=1;
        }
    }
    if (baj) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << valasz[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
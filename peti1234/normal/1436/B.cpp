#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n;
bool pr[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) pr[j]=1;
        }
    }
    while(w--) {
        cin >> n;
        int db=0, ert=n;
        while(pr[ert]) db++, ert+=n-1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if ((i+j)%n<db) cout << n << " ";
                else cout << 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
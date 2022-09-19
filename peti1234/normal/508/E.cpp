#include <bits/stdc++.h>

using namespace std;
const int c=602;
int n, l[c], r[c], p[2*c], pos, pr, ert;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];
    for (int i=n; i>=1; i--) {
        ert=1, pos=i+1;
        while(pos<=n && ert<l[i]) {
            ert+=l[pos]+1;
            pos+=(l[pos]+1)/2;
        }
        if (ert<l[i] || ert>r[i]) pr=1;
        l[i]=ert;
    }
    if (pr) cout << "IMPOSSIBLE\n";
    else {
        pos=1;
        for (int i=1; i<=2*n; i++) {
            if (!p[i]) {
                cout << "(";
                p[i+l[pos]]=1, pos++;
            } else {
                cout << ")";
            }
        }
        cout << "\n";
    }
    return 0;
}
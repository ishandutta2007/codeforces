#include <bits/stdc++.h>

using namespace std;
int n, sum, ert, t[105], db;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
        if (i==1 || t[1]>=2*t[i]) {
            db++;
            ert+=t[i];
        }
    }
    if (2*ert>sum) {
        cout << db << "\n";
        for (int i=1; i<=n; i++) {
            if (i==1 || t[1]>=2*t[i]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n, t[105], pos, ert;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        int s=abs(t[i]-(i==n ? t[1] : t[i+1]));
        if (!pos || s<ert) {
            ert=s, pos=i;
        }
    }
    cout << pos << " " << (pos==n ? 1 : pos+1) << "\n";
    return 0;
}
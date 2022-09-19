#include <bits/stdc++.h>

using namespace std;
long long n, m, t[200005], r=1, pos, el;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        long long x;
        cin >> x;
        x=x-el, el=el+x;
        while (x) {
            long long ert=min(x, t[r]-pos);
            pos+=ert, x-=ert;
            if (x) r++, pos=0;
        }
        cout << r << " " << pos << "\n";
    }
    return 0;
}
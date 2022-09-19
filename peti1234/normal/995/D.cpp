#include <bits/stdc++.h>

using namespace std;
long long t[1<<18], n, r;
long double sum, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> r;
    for (int i=0; i<(1<<n); i++) {
        cin >> t[i];
        sum+=t[i];
    }
    cout.precision(20);
    d=(1<<n);
    cout << sum/d << "\n";
    while (r--) {
        int pos, ert;
        cin >> pos >> ert;
        sum+=ert-t[pos];
        t[pos]=ert;
        cout << sum/d << "\n";
    }
    return 0;
}
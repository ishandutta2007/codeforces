#include <bits/stdc++.h>

using namespace std;
long long w, n, sum, xo, sp=1125899906842624;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        sum=0, xo=0;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sum+=x, xo^=x;
        }
        long long ert=sp+sum%2;
        sum+=ert, xo^=ert;
        cout << 3 << "\n" << ert << " ";
        cout << (2*xo-sum)/2 << " " << (2*xo-sum)/2 << "\n";

    }
    return 0;
}
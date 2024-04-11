#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
long long n, ert[c], maxi;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, xx;
        cin >> x;
        xx=x+n-i;
        ert[xx]+=x;
        maxi=max(maxi, ert[xx]);
    }
    cout << maxi << " ";
    return 0;
}
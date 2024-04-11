#include <bits/stdc++.h>

using namespace std;
int n, t[200005];
long long maxi, bal, jobb, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    y=n+1;
    while (x+1<y) {
        if (bal<jobb) {
            bal+=t[++x];
        } else {
            jobb+=t[--y];
        }
        if (bal==jobb) {
            maxi=bal;
        }
    }
    cout << maxi << "\n";
    return 0;
}
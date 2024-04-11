#include <bits/stdc++.h>

using namespace std;
long long ans, po=2, n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        ans+=po;
        po*=2;
    }
    cout << ans << "\n";
    return 0;
}
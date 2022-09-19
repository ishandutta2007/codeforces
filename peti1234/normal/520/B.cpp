#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while (m!=n) {
        if (m>n && m%2==0) m/=2;
        else m++;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
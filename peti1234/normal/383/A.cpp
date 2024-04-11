#include <bits/stdc++.h>

using namespace std;
long long n, x, sum, ans;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x==0) ans+=sum;
        else sum++;
    }
    cout << ans << "\n";
    return 0;
}
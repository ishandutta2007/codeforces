#include <bits/stdc++.h>

using namespace std;
long long n, sum, mini=105, ert, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> ert >> x;
        mini=min(mini, x);
        sum+=ert*mini;
    }
    cout << sum << "\n";
    return 0;
}
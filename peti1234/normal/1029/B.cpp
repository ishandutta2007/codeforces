#include <bits/stdc++.h>

using namespace std;
long long n, x, ut, len, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> x;
        if (x>2*ut) len=0;
        len++, ut=x;
        maxi=max(maxi, len);
    }
    cout << maxi << "\n";
    return 0;
}
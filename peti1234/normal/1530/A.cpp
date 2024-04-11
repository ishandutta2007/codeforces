#include <bits/stdc++.h>

using namespace std;
int w, n, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        maxi=0;
        while (n) {
            maxi=max(maxi, n%10);
            n/=10;
        }
        cout << maxi << "\n";
    }
    return 0;
}
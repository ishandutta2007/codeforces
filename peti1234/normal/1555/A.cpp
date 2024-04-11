#include <bits/stdc++.h>

using namespace std;
long long w, n, s=15;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        if (n%2) {
            n++;
        }
        cout << max(s, n*5/2) << "\n";
    }
    return 0;
}
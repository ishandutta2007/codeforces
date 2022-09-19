#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, l, r;
    cin >> w;
    while (w--) {
        cin >> l >> r;
        l=max(l, (r+1)/2);
        cout << min(l-1, r-l) << "\n";
    }
    return 0;
}
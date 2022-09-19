#include <bits/stdc++.h>

using namespace std;
int n, w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        cout << max(0, n-2) << "\n";
    }
    return 0;
}
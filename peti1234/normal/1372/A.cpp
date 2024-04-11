#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=n; i>=1; i--) cout << 1 << " ";
        cout << "\n";
    }
    return 0;
}
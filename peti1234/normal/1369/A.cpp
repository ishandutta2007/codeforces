#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n;
        cin >> n;
        if (n%4) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b;
        if (a%b) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}
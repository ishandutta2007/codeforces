#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b;
        cin >> a >> b;
        if (2*a>b) cout << "-1 -1\n";
        else cout << a << " " << 2*a << "\n";
    }
    return 0;
}
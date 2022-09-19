#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b;
        if (2*a>b)  cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
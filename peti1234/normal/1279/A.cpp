#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b>a) swap(a, b);
        if (c>a) swap(a, c);
        if (a<=b+c+1) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
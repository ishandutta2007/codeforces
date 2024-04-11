#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, d;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        if (a>b) swap(a, b);
        if (c>d) swap(c, d);
        if (a+c==b && b==d) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
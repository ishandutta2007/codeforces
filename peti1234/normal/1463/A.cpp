#include <bits/stdc++.h>

using namespace std;
int w, a, b, c;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c;
        if ((a+b+c)%9 || (a+b+c)/9>min({a, b, c})) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
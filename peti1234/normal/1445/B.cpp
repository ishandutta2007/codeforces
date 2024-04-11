#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, d;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        cout << max(a+b, c+d) << "\n";
    }
    return 0;
}
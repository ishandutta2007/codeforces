#include <bits/stdc++.h>

using namespace std;
int main()
{
    int q;
    cin >> q;
    while(q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << min({a, b, (a+b+c)/3}) << "\n";
    }
    return 0;
}
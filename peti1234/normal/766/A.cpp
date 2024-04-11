#include <bits/stdc++.h>

using namespace std;
string a, b;
int main()
{
    cin >> a >> b;
    if (a==b) {
        cout << -1;
        return 0;
    }
    cout << max(a.size(), b.size());
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    cin >> q;
    for (int i=1; i<=q; i++) {
        long long a, b;
        cin >> a >> b;
        cout << (a-1)*9+b << endl;
    }
    return 0;
}
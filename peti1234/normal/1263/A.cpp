#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a=min(a, b+c), b=min(b, a+c), c=min(c, a+b);
        cout << (a+b+c)/2 << "\n";
    }
    return 0;
}
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
        a=min(a, 2*b);
        b=min(b, 2*a);
        cout << (a+b)/3 << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d;
        e=c-d, f=c+d;
        if (a>b) swap(a, b);
        e=max(e, a), f=min(f, b);
        e=min(e, b), f=max(f, a);
        cout << e-a+b-f << "\n";
    }
    return 0;
}
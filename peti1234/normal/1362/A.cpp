#include <bits/stdc++.h>

using namespace std;
long long w, a, b, c, d, e;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b, d=1, e=0;
        if (a<b) swap(a, b);
        c=a/b;
        while(d<c) d*=2, e++;
        if (c*b==a && d==c) cout << (e+2)/3 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, e, f;
int main()
{
    cin >> a >> b >> c >> d >> e >> f;
    if ((a==c && c==e) || (b==d && d==f)) {
        cout << 1 << "\n";
        return 0;
    }
    if ((a==c && (f<=min(b, d) || (f>=max(b, d)))) || (a==e && (d<=min(b, f) || (d>=max(b, f)))) || (c==e && (b<=min(d, f) || (b>=max(d, f))))) {
        cout << 2 << "\n";
        return 0;
    }
    swap(a, b), swap(c, d), swap(e, f);
    if ((a==c && (f<=min(b, d) || (f>=max(b, d)))) || (a==e && (d<=min(b, f) || (d>=max(b, f)))) || (c==e && (b<=min(d, f) || (b>=max(d, f))))) {
        cout << 2 << "\n";
        return 0;
    }
    cout << 3 << "\n";
    return 0;
}
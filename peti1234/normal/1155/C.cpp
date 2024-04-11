#include <bits/stdc++.h>

using namespace std;
int n, m;
long long x;
long long fi, el;
long long gcd(long long a, long long b)
{
    if (a>b) {
        swap(a, b);
    }
    if (a==0) {
        return b;
    }
    return gcd(a, b%a);
}
int main()
{
    cin >> n >> m;
    cin >> fi;
    el=fi;
    for (int i=2; i<=n; i++) {
        long long y;
        cin >> y;
        x=gcd(x, y-el);
        el=y;
    }
    for (int i=1; i<=m; i++) {
        long long y;
        cin >> y;
        if (x%y==0) {
            cout << "YES" << " " <<   fi << " " << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
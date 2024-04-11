#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld PI = 3.14159265358979323;

int main() {
    ld n, r; cin >> n >> r;
    ld x = PI*(n-2)/n;
    ld ans = r*(cos(x/2)/(1-cos(x/2)));
    cout << fixed << setprecision(10) << ans << '\n';
}
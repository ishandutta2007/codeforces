#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ll a, b, x, y;
    ios::sync_with_stdio(false);
    cin >> a >> b >> x >> y;
    ll g = __gcd(x, y);
    x /= g;
    y /= g;
    cout << min(a / x, b / y);
    //cin.close();
    //cout.close();
    return 0;
}
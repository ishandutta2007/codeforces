#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    ll n, a, b;
    cin >> n >> a >> b;
    ll l = 0, r = a + b;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (b / m + a / m >= n && b >= m && a >= m)
            l = m;
        else 
            r = m;
    }
    cout << l;
    //system("pause");     
    return 0; 
}
#include <bits/stdc++.h>
 
using namespace std;

typedef int ll;

ll sum(ll a) {
    ll ans = 0;
    while (a > 0) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

int main() {
    ll n, m;
    cin >> n;
    for (int i = 0; i < 100000000; ++i) {
        if (sum(i) == 10) {
            --n;
            if (n == 0) {
                cout << i;
                break;
            }
        }
    }
    //system("pause");
    return 0;
}
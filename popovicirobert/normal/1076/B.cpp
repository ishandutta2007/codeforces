#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;



int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i;
    ll n;
    ios::sync_with_stdio(false);
    cin >> n;
    if(n % 2 == 0) {
        cout << n / 2;
    }
    else {
        int d = 3;
        while(1LL * d * d <= n && n % d > 0) {
            d++;
        }
        if(n % d > 0 || n == d) {
            cout << 1;
        }
        else {
            cout << 1 + (n - d) / 2;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
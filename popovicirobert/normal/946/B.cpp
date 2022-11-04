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
    ll a, b;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    while(a != 0 && b != 0) {
        if(a >= 2 * b) {
            a %= (2 * b);
        }
        else {
            if(b < 2 * a)
                break;
            b %= (2 * a);
        }
    }
    cout << a << " " << b;
    //cin.close();
    //cout.close();
    return 0;
}
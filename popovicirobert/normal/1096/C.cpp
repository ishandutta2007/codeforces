#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t > 0) {
        t--;
        int ang;
        cin >> ang;
        int a = 180 - ang, b = 180;
        int c = __gcd(a, b);
        a /= c, b /= c;
        if(a == 1) {
            b *= 2;
        }
        cout << b << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
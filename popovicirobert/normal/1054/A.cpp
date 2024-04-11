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
    int x, y, z, t1, t2, t3;
    ios::sync_with_stdio(false);
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    ll a = 1LL * abs(x - y) * t1, b = 3 * t3 + 1LL * (abs(y - x) + abs(z - x)) * t2;
    //cerr << a << " " << b;
    if(a >= b) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}
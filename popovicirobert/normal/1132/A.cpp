#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int a, b, c, d;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> d;
    if(a != d || (c > 0 && a == 0 && d == 0)) {
        cout << 0;
        return 0;
    }
    cout << 1;
    //cin.close();
    //cout.close();
    return 0;
}
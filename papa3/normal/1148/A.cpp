#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >>c;

    if (a == b) {
        cout << a+b+c*2;
        return 0;
    }

    cout << c*2 + 2*min(a, b) + 1;

    return 0;
}
/*

*/